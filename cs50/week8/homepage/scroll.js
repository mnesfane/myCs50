lastScrollPosition = 0;
lastCentered = 0;
onWayTo = null;

document.addEventListener('scroll', () => {
    const direction = window.pageYOffset - lastScrollPosition > 0 ? 'down' : 'up';
    const sections = [...document.querySelectorAll('section')];
    if(onWayTo === null)
    {
        const destIndex = direction === 'up' ? lastCentered - 1 : lastCentered + 1;
        if (destIndex >= 0 && destIndex < sections.length)
        {
            onWayTo = destIndex;
            window.scrollTo({ left: 0, top: sections[destIndex].offsetTop, behavior: 'smooth' });
            // window.scroll(0, sections[destIndex].offsetTop);
            // window.scroll(x: 0, sections[destIndex].offsetTop);
        }

    }

    // sections.forEach((section, index : number) =>{
    sections.forEach((section, index) =>{
        if(window.pageYOffset === section.offsetTop)
        {
            lastCentered = index;
            if (onWayTo === index)
            {
                onWayTo = null;
            }
        }
    });

    lastScrollPosition = window.pageYOffset;
});


// document.addEventListener('DOMContentLoaded', function(){
//     alert('off');
// });

// document.addEventListener(type: 'scroll', listener: () => {
// document.addEventListener('scroll', () => {
//     console.log("fuckoff");
// });

// let lastScrollPosition = 0;
// let lastCentered = 0;

// document.addEventListener('scroll', () => {
    //   const direction = window.pageYOffset - lastScrollPosition > 0 ? 'down' : 'up';
//   const sections = [...document.querySelectorAll('section')];
//   const destIndex = direction === 'up' ? lastCentered - 1 : lastCentered + 1;

//   if (destIndex >= 0 && destIndex < sections.length) {
    //     lastCentered = destIndex;
    //     window.scrollTo({ left: 0, top: sections[destIndex].offsetTop, behavior: 'smooth' });
    //   }

    //   lastScrollPosition = window.pageYOffset;
    // });

