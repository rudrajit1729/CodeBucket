var res = document.getElementById("res");
function action(e) {
    var btn = e.target;
    switch(btn.id){
        case "btn0": res.innerHTML += "0"; break;
        case "btn1": res.innerHTML += "1";  break;
        case "btnSum": res.innerHTML += "+";    break;
        case "btnSub": res.innerHTML += "-";    break;
        case "btnMul": res.innerHTML += "*";    break;
        case "btnDiv": res.innerHTML += "/";    break;
        case "btnClr": res.innerHTML = "";  break;
    }
}
document.getElementById("btn0").addEventListener('click', action);
document.getElementById("btn1").addEventListener('click', action);
document.getElementById("btnSum").addEventListener('click', action);
document.getElementById("btnSub").addEventListener('click', action);
document.getElementById("btnMul").addEventListener('click', action);
document.getElementById("btnDiv").addEventListener('click', action);
document.getElementById("btnClr").addEventListener('click', action);

document.getElementById("btnEqr").onclick()=function(){
    var exp = res.innerHTML;
    var re = /\d+/g;
    exp = exp.replace(re, function(match) {
        return parseInt(match, 2);
    });
    res.innerHTML = Math.floor(eval(exp)).toString(2);
};
