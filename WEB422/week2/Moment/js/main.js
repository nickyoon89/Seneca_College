$(function(){

        //moment.locale("fr-CA"); // Try out Quebec French

        // Sample date for testing
    
            let hireDate = "2010-11-07T04:00:00.000Z"; // Zsa zsa Mannering's hire date in our "Employees" Collection

        // Creating a "Moment"

            let mDate = moment(hireDate); // create a new  "moment" object

            mDate.utc(); // switch to "UTC" mode

            // display the UTC date
            let mDate1 = mDate.format('LLLL'); // Sunday, November 7, 2010 4:00 AM

            mDate.local(); // switch to "local" mode

            // display a localized date (now offset to Local Time)
            let mDate2 = mDate.format('LLLL'); // Sunday, November 7, 2010 12:00 AM

        // Display Format Options:

            let mDate3 = mDate.format('MMMM Do YYYY, h:mm:ss a');   // November 7th 2010, 12:00:00 am
            let mDate4 = mDate.format('dddd');                      // Sunday
            let mDate5 = mDate.format("MMM Do YYYY");               // Nov 7th 2010
            let mDate6 = mDate.format('[date:] MM/DD/YYYY');        // date: 11/07/2010
            let mDate7 = mDate.format();                            // 2010-11-07T00:00:00-04:00

            // Other formatting options: https://momentjs.com/docs/#/displaying/format/

        // Display Format Using Locale Options:

            let mDate8 = moment.locale();       // en (or fr if testing Quebec french)
            let mDate9 = mDate.format('LT');    // 12:00 AM        
            let mDate10 = mDate.format('LTS');  // 12:00:00 AM
            let mDate11 = mDate.format('L');    // 11/07/2010
            let mDate12 = mDate.format('l');    // 11/7/2010
            let mDate13 = mDate.format('LL');   // November 7, 2010
            let mDate14 = mDate.format('ll');   // Nov 7, 2010
            let mDate15 = mDate.format('LLL');  // November 7, 2010 12:00 AM
            let mDate16 = mDate.format('lll');  // Nov 7, 2010 12:00 AM
            let mDate17 = mDate.format('LLLL'); // Sunday, November 7, 2010 12:00 AM
            let mDate18 = mDate.format('llll'); // Sun, Nov 7, 2010 12:00 AM

        // Additional Display Options:

            // note: the display options are:

            // 'seconds'
            // 'minutes'
            // 'hours'
            // 'days'
            // 'weeks'
            // 'months'
            // 'years'

            // fromNow: https://momentjs.com/docs/#/displaying/fromnow/ / also see: https://momentjs.com/docs/#/displaying/tonow/
            let mDate19 = mDate.fromNow(); // 7 years ago
            
            // difference: https://momentjs.com/docs/#/displaying/difference/

            let mDate21 = mDate.diff(moment([2010,0,1]), 'days'); // 310
            let mDate22 = mDate.diff(moment([2010,0,1]), 'months'); // 10
            let mDate23 = mDate.diff(moment([2010,0,1]), 'years'); // 0

            // toISOString: https://momentjs.com/docs/#/displaying/as-iso-string/

            let mDate24 = mDate.toISOString(); // 2010-11-07T04:00:00.000Z (the same as what we started with)

            // daysInMonth: https://momentjs.com/docs/#/displaying/days-in-month/

            let mDate25 = mDate.daysInMonth(); // 30

        // Manipulate Options:

            // add: https://momentjs.com/docs/#/manipulating/add/

            mDate.add(5, 'days'); // Using: .format("LLLL") => Friday, November 12, 2010 12:00 AM

            // subtract: https://momentjs.com/docs/#/durations/subtract/

            mDate.subtract(5, 'days'); // Using: .format("LLLL") => Sunday, November 7, 2010 12:00 AM

            // utcOffset: https://momentjs.com/docs/#/manipulating/utc-offset/

            let mDate26 = mDate.utcOffset(); // 240 (minutes)

        // Query Options:

            // isBefore: https://momentjs.com/docs/#/query/is-before/ / also see: https://momentjs.com/docs/#/query/is-after/

            let mDate27 = mDate.isBefore(moment([2009,11,7])); // false

            // isSame: https://momentjs.com/docs/#/query/is-same/

            let mDate28 = mDate.isSame(moment([2010,10,8])); // false
            let mDate29 = mDate.isSame(moment([2010,10,8]), "month"); // true

            // isBetween: https://momentjs.com/docs/#/query/is-between/

            let mDate30 = mDate.isBetween(moment([2010,0,1]), moment()); // true

            // isDST: https://momentjs.com/docs/#/query/is-daylight-saving-time/

            let mDate31 = mDate.isDST(); // true

            // isLeapYear: https://momentjs.com/docs/#/query/is-leap-year/

            let mDate32 = mDate.isLeapYear(); // false

});