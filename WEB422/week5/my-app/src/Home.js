import React from 'react';
import MenuBar from './MenuBar';
import MainGrid from './MainGrid'

class Home extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title} />
                <MainGrid>
                        <div className="well">Home</div>
                </MainGrid>
            </div>
        );
    }
}

export default Home;