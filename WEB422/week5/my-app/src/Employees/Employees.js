import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';
import { Redirect } from 'react-router-dom';
import axios from 'axios';


class Employees extends React.Component {
    constructor(props) {
        super(props);
        this.dataSource = this.props.dataSource;
        this.state = {
            employees: [],
            redirect: false,
            targetEmployee: -1,
        }
    }

    componentDidMount() {
        axios.get(this.dataSource).then((res) => {
            this.setState({ employees: res.data });
        }).catch((err) => {
            console.log("error");
        });
    }

    handleOnClick(employeeId){
        this.setState({ 
            redirect: true,
            targetEmployee: employeeId 
        });
    }

    componentWillUnmount() {

    }
    render() {
        if (this.state.redirect) {
            return <Redirect push to={"/employee/" + this.state.targetEmployee} />;
        } else {
            return (
                <div>
                    <MenuBar title={this.props.title} />
                    <MainGrid>
                        <div className="container bootstrap-header-table">
                            <div className="row header-row">
                                <div>
                                    <div className="col-xs-4 header-column">First Name</div>
                                    <div className="col-xs-4 header-column">Last Name</div>
                                    <div className="col-xs-4 header-column">Position</div>
                                </div>
                            </div>
                            <div className="row body-rows">

                                {this.state.employees.map((element, index) => {
                                    return (
                                        <div key={element._id} className="row body-row" onClick={() => {this.handleOnClick(element._id)} }>
                                            <div className="col-xs-4 body-column">{element.FirstName}</div>
                                            <div className="col-xs-4 body-column">{element.LastName}</div>
                                            <div className="col-xs-4 body-column">{element.Position.PositionName}</div>
                                        </div>
                                    )
                                })}

                            </div>
                        </div>
                    </MainGrid>
                </div>
            );
        }
    }
}

export default Employees;