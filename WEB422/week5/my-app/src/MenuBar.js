import React from 'react';
import { Link } from 'react-router-dom'


class MenuBar extends React.Component {
    render() {
        return (
            <nav className="navbar navbar-default">
                <div className="container-fluid">
                    <div className="navbar-header">
                        <button type="button" className="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                            <span className="sr-only">Toggle navigation</span>
                            <span className="icon-bar"></span>
                            <span className="icon-bar"></span>
                            <span className="icon-bar"></span>
                        </button>
                        <span className="navbar-brand" ><Link to={{ pathname: '/' }}>React - Continued:</Link> {this.props.title} </span>
                    </div>

                    <div className="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                        <ul className="nav navbar-nav navbar-right">
                            <li className="dropdown">
                                <a className="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Collection&nbsp;<span className="caret"></span></a>
                                <ul className="dropdown-menu">
                                    <li><Link to={{ pathname: '/teams' }}>Teams</Link></li>
                                    <li><Link to={{ pathname: '/employees' }}>Employees</Link></li>
                                    <li><Link to={{ pathname: '/projects' }}>Projects</Link></li>
                                    <li><Link to={{ pathname: '/positions' }}>Positions</Link></li>
                                </ul>
                            </li>
                        </ul>
                    </div>
                </div>
            </nav>
        )
    }
}

export default MenuBar;