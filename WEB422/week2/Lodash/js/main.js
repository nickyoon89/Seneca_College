$(function(){

    // simple data for testing

let users = [
    { 'user': 'fred',    'active': false, 'age': 40 },
    { 'user': 'pebbles', 'active': false, 'age': 1  },
    { 'user': 'barney',  'active': true,  'age': 36 }
];

    // The following is a small sample of the full Lodash functionality.
    // For a full list of all Lodash methods, see: https://lodash.com/docs/4.17.4

    // Lodash "Array" methods

        // chunk: https://lodash.com/docs/4.17.4#chunk

        let chunk1 = _.chunk(['a', 'b', 'c', 'd'], 2); // => [['a', 'b'], ['c', 'd']] 
        let chunk2 = _.chunk(['a', 'b', 'c', 'd'], 3); // => [['a', 'b', 'c'], ['d']]
        let chunk3 = _.chunk(users, 2); // objects for [['fred', 'pebbles'], 'barney']

        // findIndex: https://lodash.com/docs/4.17.4#findIndex / see also: https://lodash.com/docs/4.17.4#findLastIndex and https://lodash.com/docs/4.17.4#find

        let findIndex1 = _.findIndex(users, function(user) { 
            return user.user == 'fred'; 
        }); // => 0

        // take: https://lodash.com/docs/4.17.4#take

        let take1 = _.take(users,2) // => objects for ['fred, pebbles']

    // Lodash "Collection" methods

        // filter: https://lodash.com/docs/4.17.4#filter / see also: https://lodash.com/docs/4.17.4#find

        let filter1 = _.filter(users, function(user) { // Native Version: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter
            return user.active == true;
        }); // => objects for ['barney']

        // sortby: https://lodash.com/docs/4.17.4#sortBy

        let sortBy1 = _.sortBy(users, [
            function(user) { 
                return user.user; 
            }
        ]); // => objects for ['barney', 'fred', 'pebbles']

        // forEachRight: https://lodash.com/docs/4.17.4#forEachRight / see also: https://lodash.com/docs/4.17.4#forEach

        let forEachRight1 = [];

        _.forEachRight(users, function(user) {
            forEachRight1.push(user);
        }); // iterates as ['barney', 'pebbles', 'fred']

        
    // Lodash "Number" methods

        // random: https://lodash.com/docs/4.17.4#random

        let random1 = _.random(0, 5); // => an integer between 0 and 5
        let random2 = _.random(5); // => also an integer between 0 and 5
        let random3 = _.random(5, true); // => a floating-point number between 0 and 5
        let random4 = _.random(1.2, 5.2);// => a floating-point number between 1.2 and 5.2

    // Lodash "Object" methods

        // cloneDeep: https://lodash.com/docs/4.17.4#cloneDeep and also: https://lodash.com/docs/4.17.4#clone

        let cloneDeep1 = _.cloneDeep(users); // cloneDeep1[0] !== users[0]
        
        // pick: https://lodash.com/docs/4.17.4#pick

        let pick1 = _.pick(users[0], ['user', 'age']); // => { 'user': 'fred', 'age': 40 } // note: pick !== users[0]

    // Lodash "String" methods

        // escape: https://lodash.com/docs/4.17.4#escape / see also: https://lodash.com/docs/4.17.4#unescape

        let escape1 = _.escape('fred, barney, & pebbles'); // => 'fred, barney, &amp; pebbles'

        // template: https://lodash.com/docs/4.17.4#template

        // Use the "interpolate" delimiter to create a compiled template.
        let template1 = _.template('hello <%= user %>!');
        let template1Result = template1({ 'user': users[0].user });  // => 'hello fred!'
        
        // Use the HTML "escape" delimiter to escape data property values.
        let template2 = _.template('<b><%- value %></b>');
        let template22Result = template2({ 'value': '<script>' }); // => '<b>&lt;script&gt;</b>'

        // Use the "evaluate" delimiter to execute JavaScript and generate HTML.
        let template3 = _.template('<ul>' + 
                                        '<% _.forEach(users, function(user) { %>' +
                                            '<li><%- user %></li>' + 
                                        '<% }); %>' +
                                    '</ul>');

        let template3Result = template3({ 'users': ['fred', 'barney'] }); // => '<ul><li>fred</li><li>barney</li></ul>'

        // Use the "evaluate" delimiter to execute JavaScript and generate HTML from our "users" collection.
        let template4 = _.template('<ul>' + 
                                        '<% _.forEach(users, function(user) { %>' + 
                                            '<li><%- user.user %></li>' + 
                                        '<% }); %>' + 
                                    '</ul>');

        let template4Result = template4({ 'users': users }); // => '<ul><li>fred</li><li>pebbles</li><li>barney</li></ul>'

});
