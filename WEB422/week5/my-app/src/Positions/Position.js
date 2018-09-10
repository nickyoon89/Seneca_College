import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';

class Position extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title + ": " + (this.props.id || "")} />
                <MainGrid>
                    <div className="well">TODO: Form for Position: {this.props.id}</div>
                </MainGrid>
            </div>
        );
    }
}

export default Position;