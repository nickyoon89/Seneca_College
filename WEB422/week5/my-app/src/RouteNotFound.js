import React from 'react';
import MenuBar from './MenuBar';
import MainGrid from './MainGrid';

class RouteNotFound extends React.Component {
    render() {
        return (
            <div>
                <MenuBar title={this.props.title} />
                <MainGrid>
                        <div className="well"><strong>404</strong> - I'm sorry, but we can't find what you're looking for...</div>
                </MainGrid>
            </div>
        );
    }
}

export default RouteNotFound;