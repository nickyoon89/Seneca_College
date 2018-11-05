import React, { Component } from 'react';
import MainContainer from './MainContainer'
import ProjectPanel from './ProjectPanel'
import TeamsPanel from './TeamsPanel'
import EmployeesPanel from './EmployeesPanel'

class Overview extends Component {
  render() {
    return (
        <MainContainer highlight="Overview">
              <h1 className="page-header">Overview</h1>
              <div className="row">
                <div className="col-md-4">
                  <ProjectPanel />
                </div>
                <div className="col-md-4">
                  <TeamsPanel/>
                </div>
                <div className="col-md-4">
                  <EmployeesPanel/>
                </div>
              </div>
        </MainContainer>
    );
  }
}

export default Overview;