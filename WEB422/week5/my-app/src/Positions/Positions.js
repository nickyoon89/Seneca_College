import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';

class Positions extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title} /> 
                <MainGrid>
                    <div className="well">TODO: List of Positions</div>
                </MainGrid>
            </div>
        );
    }
}

export default Positions;