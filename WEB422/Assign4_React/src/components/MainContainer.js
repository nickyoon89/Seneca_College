import React, { Component } from 'react';
import NavBar from './NavBar'
import SideBar from './SideBar'

class MainContainer extends Component{
  render(){
    return (
       <div>
            <NavBar title="WEB422 - Project Prtal"/>
            <div className="container-fluid">
                <div className="row">
                <SideBar highlight={this.props.highlight} /> 
                <div className=" col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 main">
                    {this.props.children}
                </div>
                </div>
            </div>
       </div>       
    )
  }
}

// export the component by name
export default MainContainer; 