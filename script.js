async function downloadVideo() {
    const url = document.getElementById('url').value;
    const platform = document.getElementById('platform').value;
    const loading = document.getElementById('loading');
    const result = document.getElementById('result');

    // Show loading spinner
    loading.innerHTML = '<img src="spinner.gif" alt="Loading...">';

    try {
        const response = await fetch('/download', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ url: url, platform: platform })
        });
        const data = await response.json();

        if (data.error) {
            result.innerText = 'Error: ' + data.error;
        } else {
            result.innerHTML = `
                <h2>${data.title}</h2>
                <img src="${data.thumbnail}" alt="Thumbnail">
                <a href="${data.download_url}" download>Download Video</a>
            `;
        }
    } catch (error) {
        result.innerText = 'Error: ' + error.message;
    } finally {
        // Hide loading spinner
        loading.innerHTML = '';
    }
}
