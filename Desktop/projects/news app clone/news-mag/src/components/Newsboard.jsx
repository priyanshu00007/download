import React, { useEffect, useState } from "react";
import NewsItem from "./NewsItem";
import AdComponent from "./Adcomponent";
import Navbar from "./Navbar";

const Newsboard = () => {
  const [articles, setArticles] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [category, setCategory] = useState("business");
  const [country, setCountry] = useState("us");
  const articlesPerPage = 10;

  const shuffleArray = (array) => {
    for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
  };

  useEffect(() => {
    const fetchArticles = async () => {
      try {
        const apiKey = import.meta.env.VITE_API_KEY || '31e00e4176dd4f5193f47f6e36ea02d7'; // Use your API key here
        console.log("API Key:", apiKey);

        const url = `https://newsapi.org/v2/top-headlines?country=${country}&category=${category}&pageSize=100&apiKey=${apiKey}`;
        const response = await fetch(url);

        if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
        }

        const data = await response.json();
        console.log("Fetched Data:", data);

        if (data.articles) {
          const shuffledArticles = shuffleArray(data.articles);
          setArticles(shuffledArticles);
          setLoading(false);
        } else {
          throw new Error("No articles found");
        }
      } catch (error) {
        console.error("Error fetching the news articles:", error);
        setError(error.message);
        setLoading(false);
      }
    };

    fetchArticles();
  }, [category, country]);

  if (loading) {
    return <div className="text-center">Loading...</div>;
  }

  if (error) {
    return <div className="text-center text-danger">Error: {error}</div>;
  }

  const renderArticlesWithAds = () => {
    const items = [];
    articles.forEach((news, index) => {
      items.push(
        <NewsItem
          key={`news-${index}`}
          title={news.title}
          description={news.description}
          src={news.urlToImage}
          url={news.url}
        />
      );
      if ((index + 1) % articlesPerPage === 0) {
        items.push(<AdComponent key={`ad-${index}`} />);
      }
    });
    return items;
  };

  return (
    <div>
      <Navbar setCategory={setCategory} setCountry={setCountry} />
      <h2 className="text-center">
        Latest{" "}
        <span className="highlight badge text-bg-secondary bg-danger">News</span>{" "}
        from {country.toUpperCase()} - {category.charAt(0).toUpperCase() + category.slice(1)}
      </h2>
      <div className="d-flex flex-wrap justify-content-center">
        {renderArticlesWithAds()}
      </div>
    </div>
  );
};

export default Newsboard;
