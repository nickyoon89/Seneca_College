import React, { Component } from 'react';

class NavBar extends Component{
  render(){
    return (
    <nav className="navbar navbar-inverse navbar-fixed-top">
        <div className="container-fluid">
        <div className="navbar-header">
            <a className="navbar-brand" href="/">{this.props.title}</a>
        </div>
        </div>
    </nav>
    )
  }
}

// export the component by name
export default NavBar; 