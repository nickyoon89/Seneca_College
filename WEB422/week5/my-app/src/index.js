import React from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter } from 'react-router-dom' 
//import { HashRouter } from 'react-router-dom'
import App from './App';
import './css/index.css';
import './css/bootstrap-header-table.css';

 // render the high-level "app"

 ReactDOM.render((
    <BrowserRouter>
      <App />
    </BrowserRouter>
  ), document.getElementById('root'))