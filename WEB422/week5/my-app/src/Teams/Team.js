import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';

class Team extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title + ": " + (this.props.id || "")} />
                <MainGrid>
                    <div className="well">TODO: Form for Team: {this.props.id}</div>
                </MainGrid>
            </div>
        );
    }
}

export default Team;