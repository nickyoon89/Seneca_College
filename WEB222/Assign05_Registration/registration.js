//To check password is valid when the user try to submit
function formValidation(){
    var errors = document.querySelector(".side");
    var passwd=document.signup.passwd.value;
    var rePasswd=document.signup.rePasswd.value;
    var h4 = document.createElement("h4");
    errors.innerHTML="";
    h4.appendChild(document.createTextNode("Errors"));
    if(passwd!=rePasswd){
        errors.appendChild(h4);
        errorMessage=document.createTextNode("Password is not matched");
        errors.appendChild(errorMessage);
        return false;
    }else if(passwd.length!=8||passwd.search(/[A-Z]/i)!=0||passwd.search(/\d/)==-1||passwd.search(/[A-Z]/)==-1){
        errors.appendChild(h4);
        errorMessage=document.createTextNode("Password must be 8 characters long, must start with a character, must have a least 1 digit and 1 uppercase");
        errors.appendChild(errorMessage);
        return false;
    }else{
        return true;
    }
}

//Check current input is valid
function valid(){
    //get side panel
    var errors = document.querySelector(".side");
    //get invalid focused field
    var invalid = document.querySelector("input:focus:invalid");
    //get focused field
    var current = document.querySelector("input:focus");
    //reset the side panel
    errors.innerHTML="";
    var h4 = document.createElement("h4");
    h4.appendChild(document.createTextNode("Errors"));
    var p = document.createElement("p");
    //As password and re-password is not having pattern, it check passwd even if it says it's valid
    if(invalid==null&&current!=null){
        if(current.name!="passwd"&&current.name!="rePasswd"){
            p.appendChild(document.createTextNode("The Field is Valid"))
            errors.appendChild(p);
        }else{
            //check validation of passwd
            if(current.name=="passwd"&&(current.value.length!=8||current.value.search(/[A-Z]/i)!=0||current.value.search(/\d/)==-1||current.value.search(/[A-Z]/)==-1)){
                errors.appendChild(h4);
                errorMessage=document.createTextNode("Password must be 8 characters long, must start with a character, must have a least 1 digit and 1 uppercase");
                errors.appendChild(errorMessage);
            //check if re-password is same as password
            }else if(document.querySelector("#passwd").value!=current.value){
                errors.appendChild(h4);
                errorMessage=document.createTextNode("Password is not matched");
                errors.appendChild(errorMessage);
            //otherwise, it's valid
            }else{
                p.appendChild(document.createTextNode("The Field is Valid"))
                errors.appendChild(p);
            }
        }
    }else if(current!=null){
        errors.appendChild(h4);
        var errorMessage;
        //when there is nothing input, it shows this message
        if(current.value.trim()==""){
            errorMessage=document.createTextNode("The field is required");
            errors.appendChild(errorMessage);
        }
        else{
        //different error messages for current input
        switch (current.name) {
            case "streetName":
                errorMessage=document.createTextNode("Street cannot contain digits");
                errors.appendChild(errorMessage);
                break;
            case "city":
                errorMessage=document.createTextNode("City contains letters only");
                errors.appendChild(errorMessage);
                break;
            case "postCd":
                errorMessage=document.createTextNode("Postal Code should (Letter Digit Letter Digit Letter Digit)");
                errors.appendChild(errorMessage);
                break;
            case "phoneNo":
                errorMessage=document.createTextNode("Phone Number should be ###-###-####");
                errors.appendChild(errorMessage);
                break;
            case "email":
                errorMessage=document.createTextNode("Email address is invalid");
                errors.appendChild(errorMessage);
                break;
            case "userName":
                errorMessage=document.createTextNode("Username must start with a letter, must have at least 6 characters");
                errors.appendChild(errorMessage);
                break;            
            default:
                break;
            }
        }
    }
}