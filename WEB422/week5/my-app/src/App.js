import React from 'react';
import { Route, Switch } from 'react-router-dom'


// Import Routes

import Home from './Home';

import Teams from './Teams/Teams';
import Team from './Teams/Team';

import Employees from './Employees/Employees';
import Employee from './Employees/Employee';

import Projects from './Projects/Projects';
import Project from './Projects/Project';

import Positions from './Positions/Positions';
import Position from './Positions/Position';

import RouteNotFound from './RouteNotFound';

class App extends React.Component {
    render() {
        return (
            <Switch>
                <Route exact path='/' render={() => (
                        <Home title="Home" />
                )}/>
                <Route exact path='/teams' render={() => (
                        <Teams title="Teams" />
                )}/>
                <Route path='/team/:teamId' render={(props) => (
                        <Team title={"Team " + props.match.params.teamId} id={props.match.params.teamId}/>
                )}/>
                <Route exact path='/employees' render={() => (
                        <Employees title="Employees" dataSource = "your teams api url/employees" /> // change "your teams api url" to your Teams API url on Heroku
                )}/>
                <Route path='/employee/:employeeId' render={(props) => (
                        <Employee title="Employee" dataSource={"your teams api url/employee/" + props.match.params.employeeId } /> // change "your teams api url" to your Teams API url on Heroku
                )}/>
                <Route exact path='/projects' render={() => (
                        <Projects title="Projects" />
                )}/>
                <Route path='/project/:projectId' render={(props) => (
                        <Project title="Project" id={props.match.params.projectId}/>
                )}/>
                <Route exact path='/positions' render={() => (
                        <Positions title="Positions" />
                )}/>
                <Route path='/position/:positionId' render={(props) => (
                        <Position title="Position" id={props.match.params.positionId}/>
                )}/>
                <Route render={() => (
                        <RouteNotFound title="404 - Not Found" />
                )}/>
            </Switch>
        );
    }
}

export default App;
