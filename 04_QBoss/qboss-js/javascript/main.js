
function cmabio(c){
    return [Xw + c[0], Yw - c[1]]
}

function main(){
    var canvas = document.getElementById("cloth")
    var lienzo = document.getElementById("cloth").getContext("2d")

    cambia([2,3])
    lienzo.arc(0, 0, 50, 0, 2 * Math.PI)
    lienzo.stroke()
}

