// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm"}
    ]
};

window.onload=function(){
    var videoContainer = document.querySelector("#videoContents");
    var videoContents='<video width="'+video.width+'" height="'+video.height+'" ';
    if(video.controls) videoContents+="controls>";
    else videoContents+=">";
    video.source.forEach(source => {
        videoContents+='<source src="'+source.src+'" type="'+source.type+'">';
    });
    videoContents+="</video>";
    videoContainer.innerHTML+=videoContents;
}