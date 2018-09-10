var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// create the positionSchema
var positionSchema = new Schema({
    PositionName: String,
    PositionDescription: String,
    PositionBaseSalary: Number
});

// make this schema available to the Node application
module.exports = positionSchema;