/**********************************
 *          ALL DATA              *
 *  write your CustomerDB Object  *
 *      BELOW this Object         *
 **********************************/

var allData = [
    {type:"store", data:{store_id: 297, name: "Scotiabank - Main Branch", address_id: 1023}},
    {type:"store", data:{store_id: 614, name: "Scotiabank - Hamilton", address_id: 1984}},
    {type:"store", data:{store_id: 193, name: "Scotiabank - Mississauga", address_id: 1757}},
    {type:"customer", data:{customer_id: 26, store_id:297, first_name: "Dave", last_name: "Bennett", email: "dbennett@gmail.com", address_id: 4536, add_date: null}},
    {type:"customer", data:{customer_id: 59, store_id:193, first_name: "John", last_name: "Stevens", email: "jstevens22@hotmail.com", address_id: 2473, add_date: null}},
    {type:"customer", data:{customer_id: 29, store_id:614, first_name: "Sarah", last_name: "Pym", email: "spym99@hotmail.com", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 63, store_id:297, first_name: "Steven", last_name: "Edwards", email: "steven2231@hotmail.com", address_id: 1836, add_date: null}},
    {type:"customer", data:{customer_id: 71, store_id:614, first_name: "Martin", last_name: "Scott", email: "mdog33@gmail.com", address_id: 2727, add_date: null}},
    {type:"customer", data:{customer_id: 24, store_id:614, first_name: "Jonathan", last_name: "Pym", email: "jjpym@yahoo.ca", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 36, store_id:193, first_name: "Kaitlyn", last_name: "Adams", email: "katy38@hotmail.com", address_id: 5464, add_date: null}},
    {type:"customer", data:{customer_id: 73, store_id:297, first_name: "Melissa", last_name: "Bennett", email: "mbennett@gmail.com", address_id: 4536, add_date: null}},         
    {type:"address", data:{address_id: 1023, address: "2895 Yonge St.", city:"Toronto", province:"ON", postal_code:"L4C02G"}},
    {type:"address", data:{address_id: 1984, address: "3611 Main St. West", city:"Hamilton", province:"ON", postal_code:"R5O8H5"}},
    {type:"address", data:{address_id: 1757, address: "1177 Ontario St. Unit 8", city:"Mississauga", province:"ON", postal_code:"L9H6B3"}},
    {type:"address", data:{address_id: 4536, address: "3945 John St.", city: "Ajax", province: "ON", postal_code: "L7M4T9"}},
    {type:"address", data:{address_id: 2473, address: "391 Baker St. Apt 231", city: "Mississauga", province: "ON", postal_code: "M4T8S3"}},
    {type:"address", data:{address_id: 1611, address: "183 City Ct.", city: "Hamilton", province: "ON", postal_code: "J3T9V2"}},
    {type:"address", data:{address_id: 1836, address: "67 Rhymer Ave.", city: "Stouffville", province: "ON", postal_code: "L3C8H4"}},
    {type:"address", data:{address_id: 2727, address: "287 Brant St. Apt 4A", city: "Waterdown", province: "ON", postal_code: "R93G3P"}},
    {type:"address", data:{address_id: 5464, address: "11 New St. Apt 2B", city: "Brampton", province: "ON", postal_code: "L694R7"}},
];

 /*  Write your CustomerDB Object Here.  Do not forget to uncomment the "TEST DATA" section
     when you're ready.  Your code is required to run against these tests before you submit */

var CustomerDB = {
    customers: [],
    addresses: [],
    stores: [],

    insertData: function(allData){
        allData.forEach( insData => {
            if(insData.type=="customer") this.addCustomer(insData.data);
            else if(insData.type=="address") this.addAddress(insData.data);
            else if(insData.type=="store") this.addStore(insData.data);
        });
    },

    //Customer related Methods
    addCustomer: function(customerObj){
        customerObj.add_date=new Date();
        this.customers.push(customerObj);
    },
    outputCustomerById: function(customer_id){
        this.customers.forEach(customerObj => {
            if(customerObj.customer_id==customer_id){
                var addressObj=this.getAddressById(customerObj.address_id);
                console.log("Customer "+customerObj.customer_id+": "+customerObj.first_name+" "+customerObj.last_name+" ( "+customerObj.email+" )");
                console.log("Home Address: "+addressObj.address+" "+addressObj.city+", "+addressObj.province+". "+addressObj.postal_code);
                console.log("Joined: "+customerObj.add_date+"\n");
            }
        });
    },
    outputAllCustomers: function(){
        console.log("All Customers\n");
        this.customers.forEach(customerObj => {
            var addressObj=this.getAddressById(customerObj.address_id);
            console.log("Customer "+customerObj.customer_id+": "+customerObj.first_name+" "+customerObj.last_name+" ( "+customerObj.email+" )");
            console.log("Home Address: "+addressObj.address+" "+addressObj.city+", "+addressObj.province+". "+addressObj.postal_code);
            console.log("Joined: "+customerObj.add_date+"\n");
        });
    },
    outputCustomersByStore: function(store_id){
        console.log("Customers in Store: "+this.getStoreById(store_id).name+"\n");
        this.customers.forEach(customerObj => {
            if(customerObj.store_id==store_id){
                var addressObj=this.getAddressById(customerObj.address_id);
                console.log("Customer "+customerObj.customer_id+": "+customerObj.first_name+" "+customerObj.last_name+" ( "+customerObj.email+" )");
                console.log("Home Address: "+addressObj.address+" "+addressObj.city+", "+addressObj.province+". "+addressObj.postal_code);
                console.log("Joined: "+customerObj.add_date+"\n");
            }
        });
    },
    removeCustomerById: function(customer_id){
        var count=0;
        this.customers.forEach(customerObj => {
            if(customerObj.customer_id==customer_id){
                this.customers.splice(count,1);
                this.removeAddressById(customerObj.address_id);
            }
            count++;
        });
    },
    
    //Address related Methods
    addAddress: function(addressObj){
        this.addresses.push(addressObj);
    },
    getAddressById: function(address_id){
        var result;
        this.addresses.forEach(addressObj => {
            if(addressObj.address_id==address_id) result = addressObj;
        });
        return result;
    },
    outputAllAddresses: function(){
        console.log("All Addresses\n");
        this.addresses.forEach(addressObj => {
            console.log("Address "+addressObj.address_id+": "+addressObj.address+" "+addressObj.city+", "+addressObj.province+". "+addressObj.postal_code+"\n");
        });
    },
    removeAddressById: function(address_id){
        var commonUse=0;
        var savedIndex=-1;
        this.customers.forEach(customerObj => {
            if(customerObj.address_id==address_id) commonUse++;
        });
        if(commonUse==0) {
            for (var i =0;i < this.addresses.length;i++) {
                const addressObj = this.addresses[i];
                if(addressObj.address_id==address_id) savedIndex=i;
            }
            if(savedIndex!=-1) this.addresses.splice(savedIndex,1);
        }
    },

    //Store related Methods
    addStore:function(storeObj){
        this.stores.push(storeObj);
    },

    getStoreById: function(store_id){
        var result;
        this.stores.forEach(storeObj => {
            if(storeObj.store_id==store_id) result = storeObj;
        });
        return result;
    },

    outputAllStores: function(){
        console.log("All Stores\n");
        this.stores.forEach(storeObj => {
            console.log("Store "+storeObj.store_id+": "+storeObj.name);
            var addressObj=this.getAddressById(storeObj.address_id);
            console.log("Location: "+addressObj.address+" "+addressObj.city+", "+addressObj.province+". "+addressObj.postal_code+"\n");
        });
    }
};

/**********************************
 *          TEST DATA             *
 *  write your CustomerDB Object  *
 *      ABOVE this code           *
 *                                *
 *  Uncomment this block of code  *
 *  when you're ready to test     *
 *  your CustomerDB Object        *
 *                                *
 *  You MUST Hand in your code    *
 *  with the test data            *
 *  uncommented, as this will     *
 *  help check your code for      *
 *  correctness                   *
 **********************************/



// Insert all Data into the Database

CustomerDB.insertData(allData);

// output all customers

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n"); 

// output all stores

console.log("CustomerDB.outputAllStores();\n\n--------------------------\n\n");
CustomerDB.outputAllStores();
console.log("--------------------------\n\n"); 

// output all customers in the "Main Branch"

console.log("CustomerDB.outputCustomersByStore(297);\n\n--------------------------\n\n");
CustomerDB.outputCustomersByStore(297);
console.log("--------------------------\n\n"); 

// remove Customer Dave Bennett (customer_id 26) and Martin Scott (customer_id 71)

console.log("CustomerDB.removeCustomerById(26);\nCustomerDB.removeCustomerById(71);\n\n");
CustomerDB.removeCustomerById(26);
CustomerDB.removeCustomerById(71);
console.log("--------------------------\n\n"); 

// output all customers again
// NOTE: Dave Bennett and Martin Scott should be missing

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses again
// NOTE: only addrss 287 Brant St. Apt 4A Waterdown, ON. R93G3P should be missing

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n"); 


