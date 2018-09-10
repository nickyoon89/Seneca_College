var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// create the employeeSchema
var employeeSchema = new Schema({
    FirstName: String,
    LastName: String,
    AddressStreet: String,
    AddressState: String,
    AddressCity: String,
    AddressZip: String,
    PhoneNum:String,
    Extension: Number,
    Position: { type: Schema.Types.ObjectId, ref: 'Position' },
    HireDate: Date,
    SalaryBonus: Number
});

// make this schema available to the Node application
module.exports = employeeSchema;