import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';

class Project extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title + ": " + (this.props.id || "")} />
                <MainGrid>
                    <div className="well">TODO: Form for Project: {this.props.id}</div>
                </MainGrid>
            </div>
        );
    }
}

export default Project;