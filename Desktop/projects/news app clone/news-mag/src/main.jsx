import dotenv from 'dotenv';
import React from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter } from 'react-router-dom'; // Correct import statement for BrowserRouter
import App from './App';

dotenv.config();
const apiKey = process.env.REACT_APP_API_KEY;

// Render your application
ReactDOM.render(
  <React.StrictMode>
    <BrowserRouter>
      <App apiKey={apiKey} />
    </BrowserRouter>
  </React.StrictMode>,
  document.getElementById('root')
);
