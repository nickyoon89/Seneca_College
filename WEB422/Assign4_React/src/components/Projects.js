import React, { Component } from 'react';
import MainContainer from './MainContainer'
import moment from 'moment';
import axios from 'axios';

class Projects extends Component {
    state={
        projects:[]
    }
    componentDidMount(){
        axios.get("https://web422-server.herokuapp.com/projects").then((res) => { // this would be a URI from your "Teams API"
            this.setState({
                projects: res.data
            });
        }).catch((err) => {
            console.log("error")
        });
    }
    render() {
      return (
        <MainContainer highlight="Projects">
            <h1 className="page-header">Projects</h1>
            <table className="table table-striped table-bordered">
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Description</th>
                        <th>Start Date</th>
                        <th>End Date</th>
                    </tr>
                </thead>
                <tbody>
                {this.state.projects.map(project => {
                    let endDate ="";
                    if (project.ProjectEndDate==null) endDate="n/a";
                    else endDate = moment(project.ProjectEndDate).utc().format('LL');
                    return (
                        <tr key={project._id}>
                            <td>{project.ProjectName}</td>
                            <td>{project.ProjectDescription}</td>                            
                            <td>{moment(project.ProjectStartDate).utc().format('LL')}</td>
                            <td>{endDate}</td>
                        </tr>
                    );
                })}
                </tbody>
            </table>
        </MainContainer>
      )
    }
}
export default Projects