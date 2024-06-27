from flask import Flask, request, jsonify
from flask_cors import CORS
import instaloader
import yt_dlp
import traceback
import os

app = Flask(__name__)
CORS(app)

# Instagram session id
INSTAGRAM_SESSION_ID = os.environ.get('INSTAGRAM_SESSION_ID')

def get_instagram_video(url):
    L = instaloader.Instaloader()
    try:
        if INSTAGRAM_SESSION_ID:
            L.context.session.cookies.set("sessionid", INSTAGRAM_SESSION_ID, domain="instagram.com")
        else:
            print("Warning: Instagram session ID not provided. Some videos may not be accessible.")

        shortcode = url.split("/")[-2]
        post = instaloader.Post.from_shortcode(L.context, shortcode)
        if post.is_video:
            return {
                'title': post.title or "Instagram Video",
                'thumbnail': post.url,
                'download_url': post.video_url
            }
        else:
            return {'error': 'This Instagram post is not a video.'}
    except instaloader.exceptions.InstaloaderException as e:
        return {'error': f"Instaloader error: {str(e)}", 'traceback': traceback.format_exc()}
    except Exception as e:
        return {'error': f"Error processing Instagram URL: {str(e)}", 'traceback': traceback.format_exc()}

def get_youtube_video(url):
    try:
        ydl_opts = {}
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            info = ydl.extract_info(url, download=False)
            formats = info['formats']
            best_format = next(f for f in formats if f['vcodec'] != 'none' and f['acodec'] != 'none')
            return {
                'title': info['title'],
                'thumbnail': info['thumbnail'],
                'download_url': best_format['url']
            }
    except Exception as e:
        return {'error': f"Error processing YouTube URL: {str(e)}", 'traceback': traceback.format_exc()}

@app.route('/download', methods=['POST'])
def download_video():
    data = request.json
    url = data.get('url')
    platform = data.get('platform')

    if not url:
        return jsonify({'error': 'URL is required'}), 400

    if platform == 'instagram':
        video_info = get_instagram_video(url)
    elif platform == 'youtube':
        video_info = get_youtube_video(url)
    else:
        return jsonify({'error': 'Invalid platform'}), 400

    if 'error' in video_info:
        return jsonify(video_info), 500
    else:
        return jsonify(video_info)

@app.route('/test', methods=['GET'])
def test():
    return jsonify({'message': 'Backend is working!'}), 200

if __name__ == '__main__':
    app.run(debug=True)