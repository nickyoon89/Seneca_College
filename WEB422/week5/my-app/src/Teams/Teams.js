import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';

class Teams extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title} /> 
                <MainGrid>
                    <div className="well">TODO: List of Teams</div>
                </MainGrid>
            </div>
        );

    }
}

export default Teams;