import React from 'react';

class Alert extends React.Component {
    render() {
        if(this.props.visible === true){
            return (
                <div className={"alert alert-" + this.props.type }>
                    {this.props.message}
                </div>
            );
        }else{
            return null;
        }
    }
}

export default Alert;