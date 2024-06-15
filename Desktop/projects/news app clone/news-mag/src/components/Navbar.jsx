import React from "react";

const Navbar = ({ setCategory, setCountry }) => {
  const categories = ['business', 'entertainment', 'health', 'science', 'sports', 'technology'];
  const countries = [
    { code: 'us', name: 'United States' },
    { code: 'in', name: 'India' },
    { code: 'gb', name: 'United Kingdom' },
    { code: 'ca', name: 'Canada' },
    { code: 'au', name: 'Australia' },
  ];

  return (
    <nav className="navbar navbar-expand-lg navbar-dark bg-dark" data-bs-theme="dark">
      <div className="container-fluid">
        <a className="navbar-brand" href="#">
          <span className="badge text-bg-secondary bg-light text-dark fs-4 "> News-Mag</span>
        </a>
        <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className="collapse navbar-collapse" id="navbarSupportedContent">
          <ul className="navbar-nav me-auto mb-2 mb-lg-0">
            <li className="nav-item">
              <a className="nav-link active" aria-current="page" href="#">Home</a>
            </li>
            <li className="nav-item dropdown">
              <a className="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                Categories
              </a>
              <ul className="dropdown-menu">
                {categories.map((category) => (
                  <li key={category}>
                    <a className="dropdown-item" href="#" onClick={() => setCategory(category)}>{category}</a>
                  </li>
                ))}
              </ul>
            </li>
            <li className="nav-item dropdown">
              <a className="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                Countries
              </a>
              <ul className="dropdown-menu">
                {countries.map((country) => (
                  <li key={country.code}>
                    <a className="dropdown-item" href="#" onClick={() => setCountry(country.code)}>{country.name}</a>
                  </li>
                ))}
              </ul>
            </li>
          </ul>
          
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
