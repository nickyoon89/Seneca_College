// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};

window.onload=function(){
    var audioContainer=document.querySelector("#audioContents");
    var audioContents;
    if(audio.controls) audioContents="<audio controls>";
    else audioContents="<audio>";
    audio.source.forEach(audioData => {
        audioContents+='<source src="'+audioData.src+'" type="'+audioData.type+'"></source>';
    });
    audioContents+="</audio>";
    audioContainer.innerHTML+=audioContents;
}