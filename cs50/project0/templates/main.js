
var counter = 0;
var timeleft = 45;
var timeleftbySec = 1 * 60;

function converttotimer(s)
{
    var min = Math.floor(s / 60);
    var sec = s % 60;
    if (min <= 10 || sec <=10)
    {
        if (min < 10 && sec <10)
        {
            return `0${min}` + ':' + `0${sec}`;
        }
        else if(min < 10)
        {
            return `0${min}` + ':' + sec;
        }
        else if(sec < 10)
        {
            return min + ':' + `0${sec}`;
        }
    }
    return min + ':' + sec;
}
document.addEventListener('DOMContentLoaded', function(){
    var buttons = document.getElementsByClassName("b");

    for (var i = 0; i < buttons.length; i++)
    {
        buttons[i].addEventListener("click", function(){
            this.classList.add("clicked");
            var buttindex = Array.prototype.indexOf.call(buttons, this);
            if (buttindex === 1)
            {
                document.body.style.backgroundColor = "#208B83";
                this.classList.add("greenLook");
                this.classList.add("greenTimer")
            }
        });
    }
    document.querySelector(".minutes").innerHTML = converttotimer(timeleftbySec);
    let interval = setInterval(() =>{
        timeleftbySec--;
        document.querySelector(".minutes").innerHTML = converttotimer(timeleftbySec);
        if ( timeleftbySec == 0)
        {
            clearInterval(interval);
        }
    }, 1000);
});

