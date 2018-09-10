import React from 'react';
import MenuBar from '../MenuBar';
import MainGrid from '../MainGrid';
import Alert from '../Alert';
import axios from 'axios';
import _ from 'lodash';

class Employee extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            employee: {}, 
            dataLoaded: false,
            alertStatus: "",
            alertMessage: "",
            alertVisible: false
        }

        this.handleInputChange = this.handleInputChange.bind(this); // ensure that "this" in the event callback refers to Employee
        this.handleSubmit = this.handleSubmit.bind(this); // ensure that "this" in the event callback refers to Employee
    }

    componentDidMount() {
        axios.get(this.props.dataSource).then((res) => {
            this.setState({ 
                employee: res.data[0],
                dataLoaded: true 
            });
        }).catch((err) => {
            this.setState({ 
                dataLoaded: true 
            });
        });
    }

    handleInputChange(event){
        const target = event.target;
        const value = target.type === 'checkbox' ? target.checked : target.value;
        const name = target.name;

        this.setState(function(prevState){
            // make a shallow copy of the current ("previous") state
            var updatedEmployee = _.extend({}, prevState.employee);
            // only update the relavent field on the new object
            updatedEmployee[name] = value;

            return {employee: updatedEmployee}
        });

       
    }

    handleSubmit(event){ 

        event.preventDefault();

        axios.put(this.props.dataSource, this.state.employee).then((res) => {
            this.setState({
                alertVisible: true,
                alertStatus: "success",
                alertMessage: "Data Saved!"
            });

            setTimeout(()=>{this.setState({alertVisible: false})},1200); // hide the alert after 1200 seconds
        }).catch((err) => {
           
            this.setState({
                alertVisible: true,
                alertStatus: "danger",
                alertMessage: "Could Not Save the data"
            });

           setTimeout(()=>{this.setState({alertVisible: false})},1200); // hide the alert after 1200 seconds
        });
    }

    // NOTE: This code could be better optomized by writing Components for the "row", "column" and form input elements

    render() {
        if(this.state.dataLoaded === true){
            if (this.state.employee._id) { // only render the full view if we have an employee
                return (
                    <div>
                        <MenuBar title={this.props.title + ": " + (this.state.employee.FirstName + " " + this.state.employee.LastName)} />
                        <MainGrid>

                            <form onSubmit={this.handleSubmit}>
                                <div className="row">
                                    <div className="col-md-6">
                                        <label> First Name: </label>
                                        <input className="form-control" type="text" name="FirstName" value={this.state.employee.FirstName} onChange={this.handleInputChange} />
                                    </div>
                                    <div className="col-md-6">
                                        <label> Last Name: </label>
                                        <input className="form-control" type="text" name="LastName" value={this.state.employee.LastName} onChange={this.handleInputChange} />
                                    </div>
                                </div>
                                <div className="row">
                                    <div className="col-md-3">
                                        <label> Address: </label>
                                        <input className="form-control" type="text" name="AddressStreet" value={this.state.employee.AddressStreet} onChange={this.handleInputChange} />
                                    </div>
                                    <div className="col-md-3">
                                        <label> State: </label>
                                        <input className="form-control" type="text" name="AddressState" value={this.state.employee.AddressState} onChange={this.handleInputChange} />
                                    </div>
                                    <div className="col-md-3">
                                        <label> City: </label>
                                        <input className="form-control" type="text" name="AddressCity" value={this.state.employee.AddressCity} onChange={this.handleInputChange} />
                                    </div>
                                    <div className="col-md-3">
                                        <label> Zip Code: </label>
                                        <input className="form-control" type="text" name="AddressZip" value={this.state.employee.AddressZip} onChange={this.handleInputChange} />
                                    </div>
                                </div>
                                <div className="row">
                                    <div className="col-md-2">
                                        <label> Phone Number: </label>
                                        <input className="form-control" type="text" name="PhoneNum" value={this.state.employee.PhoneNum} onChange={this.handleInputChange} />
                                    </div>

                                    <div className="col-md-1">
                                        <label> Ext: </label>
                                        <input className="form-control" type="text" name="Extension" value={this.state.employee.Extension} onChange={this.handleInputChange} />
                                    </div>

                                    <div className="col-md-3">
                                        <label> Position: </label>
                                        <input className="form-control" type="text" name="Position" value={this.state.employee.Position.PositionName} disabled />
                                    </div>

                                    <div className="col-md-3">
                                        <label> Hire Date: </label>
                                        <input className="form-control" type="text" name="HireDate" value={new Date(this.state.employee.HireDate).toLocaleDateString()} disabled/>
                                    </div>

                                    <div className="col-md-3">
                                    <label> Salary Bonus: </label>
                                        <div className="input-group">
                                            
                                            <div className="input-group-addon">$</div>
                                            <input className="form-control" type="text" name="SalaryBonus" value={this.state.employee.SalaryBonus} onChange={this.handleInputChange} />
                                            <div className="input-group-addon">.00</div>
                                        </div>
                                    </div>
                                </div>

                                <div className="row">
                                    <div className="col-md-12">
                                        <button className="btn btn-primary pull-right" type="submit">Update Employee</button>
                                        
                                    </div>
                                </div>
                            </form>
                            <Alert type={this.state.alertStatus} message={this.state.alertMessage} visible={this.state.alertVisible}/>
                        </MainGrid>
                    </div>
                );
            } else { // return "employee not found"
                return (
                    <div>
                        <MenuBar title={this.props.title + ": Not Found"} />
                        <MainGrid>
                            <Alert type={"danger"} message={"Employee Not Found"} visible={true}/>
                        </MainGrid>
                    </div>
                );
            }
        }else{ // return nothing, since the data hasn't finished yet
            return null;
        }
    }
}

export default Employee;




