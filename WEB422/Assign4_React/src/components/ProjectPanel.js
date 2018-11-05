import React, { Component } from 'react';
import { Link } from 'react-router-dom';
import moment from 'moment';
import axios from 'axios';

class ProjectPanel extends Component{
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

    render(){        
        return (
            <div className="panel panel-default">
                <div className="panel-heading">
                    <h3 className="panel-title">Projects</h3>
                </div>
                <div className="panel-body">
                    <div className="table-responsive overview-table">
                    <table className="table table-striped table-bordered">
                        <tbody>
                        {this.state.projects.map(project => {
                            let activeDate = moment().diff(moment(project.ProjectStartDate), 'days');
                            return (
                                <tr key={project._id}>
                                    <td>{project.ProjectName}</td>
                                    <td>{'Active '+ activeDate + ' days'}</td>
                                </tr>
                            );
                        })}
                        </tbody>
                    </table>
                    </div>
                    <Link to="/projects" className="btn btn-primary form-control">View All Project Data</Link>
                </div>
            </div>
        )
    }
}
export default ProjectPanel