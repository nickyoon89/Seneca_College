$(function() { // this is the same as: $(document).ready(function(){

    $("#cancelForm").on("click", function(e){
        e.preventDefault();
        clearForm();
    });

    $("#populateForm").on("click", function(e){
        e.preventDefault();
        populateForm()
    });

    $("#submitForm").on("click", function(e){
        e.preventDefault();
        console.log(getFormValues())
    });

    // show a modal with a "loading" button state

    $("#loadingDelay").on("click", function(e){
        let $btn = $(this).button('loading');
        
        setTimeout(function(){

            $('#myModal').modal({
                backdrop: 'static', // disable clicking on the backdrop to close
                keyboard: false // disable using the keyboard to close
            });

            $btn.button('reset');

        }, 1000);
    });

    // wire up a popover

    $("#dynamicPopover").popover({
        template: '<div class="popover" role="tooltip"><div class="arrow"></div>' + 
                  '<h3 class="popover-title"></h3><div class="popover-content"></div></div>',
        title: 'Tooltip Title',
        content: 'Lorem ipsum dolor sit amet',
        placement: 'top',
        trigger: 'click'
    });

    // show a dynamic alert

    $("#dynamicAlert").on("click", function(e){

        let alertMessage = "Warning Message from jQuery - this alert will close in 3 seconds";
        let alertTemplate = '<div class="alert alert-warning alert-dismissible fade in" role="alert">' +
                                '<button type="button" class="close" data-dismiss="alert" aria-label="Close">' + 
                                    '<span aria-hidden="true">×</span>' +
                                '</button>' +
                                '<strong>Warning</strong>' + alertMessage + 
                            '</div>';

        let $warningAlert = $(alertTemplate);

        $("#mainColumn").append($warningAlert);

        setTimeout(function(){
            $warningAlert.alert('close'); 
        },3000)
        
    });
   
});

function populateForm(){
    $("#inputEmail").val("from jQuery"); // set to "from jQuery"
    $("#inputPassword").val("abc"); // set to "abc"
    $("#textarea1").val("from jQuery"); // set to "from jQuery"
    $("#select1").val(3); // set to "Three"
    $("#select2").val([4,5]); // set to "Four" and "Five"

    $("#checkbox1").prop("checked", true); // set to "checked"
    $('input[name=optionsRadios][value=' + 'option2' + ']').prop("checked", true ); // set "option 2" to checked
}

function getFormValues(){
    return {
        inputEmail: $("#inputEmail").val(),
        inputPassword: $("#inputPassword").val(),
        textarea1: $("#textarea1").val(),
        select1: $("#select1").val(),
        select2: $("#select2").val(),
        
        checkbox1: $("#checkbox1").prop("checked"), // true / false
        optionsRadios: $('input[name=optionsRadios]:checked').val(), // get the value of the checked "optionsRadio"
    };
}

function clearForm(){
    $(":input:not(:checkbox):not(:radio)").val(""); // do not remove "value" from checkboxes or radio buttons
    $("input:checkbox").prop("checked", false);
    $("input:radio").prop("checked", false);
}
