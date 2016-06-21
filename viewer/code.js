var scale = 30;
var origin_x = 500;
var origin_y = 500;


var SEQ = "110101010111101000100110101010111101000100010000100010001011110101010111101010101111010001000100001000100010111101010101101000010001000101111010101011";
var path = [-1,1,-1,-1,0,-1,1,1,-1,0,1,1,0,0,-1,0,0,0,-1,1,-1,0,-1,1,0,-1,1,-1,-1,1,-1,1,0,1,1,-1,0,-1,0,0,1,-1,0,0,-1,1,0,0,1,-1,-1,0,-1,1,-1,1,-1,1,0,1,-1,0,-1,-1,1,1,-1,0,1,1,0,-1,-1,0,1,1,-1,0,-1,0,0,0,0,0,-1,-1,0,0,1,1,0,0,0,1,0,0,0,0,0,-1,1,1,0,-1,-1,1,0,1,1,-1,-1,1,0,0,1,0,0,-1,1,0,1,-1,-1,0,1,-1,1,0,0,-1,0,0,1,-1,-1,1,0,0,0,-1,-1,0,0,1,1,-1,-1,0,-1];
var bonsai_path = [
    ['moveTo', origin_x, origin_y]
];

var turn_map = {
    0: "north",
    1: "east",
    2: "south",
    3: "west"
};

var turn = {
    "north": ['lineBy', 0, -scale],
    "south": ['lineBy', 0, scale],
    "east": ['lineBy', -scale, 0],
    "west": ['lineBy', scale, 0]
};
var north = ['lineBy', 0, -scale];
var south = ['lineBy', 0, scale];
var east = ['lineBy', scale, 0];
var west = ['lineBy', -scale, 0];

var facing = 0;
var circle_x = origin_x;
var circle_y = origin_y;



var c = new Polygon(circle_x, circle_y, 12, 6);

if (parseInt(SEQ[0]) == 1){
    c.fill('black').addTo(stage);
}else{
    c.fill('grey').addTo(stage);
}





for (var i = 0; i < path.length; i++) {

    facing += parseInt(path[i]);
    if (facing == 4){
        facing = 0;
    }
    if (facing == -1){
        facing = 3;
    }
    console.log(parseInt(path[i]));
    //console.log(facing);

    switch (facing){
        case 0:
            bonsai_path.push(north);
            circle_x += north[1];
            circle_y += north[2];
            break;
        case 1:
            bonsai_path.push(east);
            circle_x += east[1];
            circle_y += east[2];
            break;
        case 2:
            bonsai_path.push(south);
            circle_x += south[1];
            circle_y += south[2];
            break;
        case 3:
            bonsai_path.push(west);
            circle_x += west[1];
            circle_y += west[2];
            break;
    }

    var c = new Polygon(circle_x, circle_y, 12, 6);
    if (parseInt(SEQ[i]) == 1){
        c.fill('black').addTo(stage);
    }else{
        c.fill('grey').addTo(stage);
    }
}


var p = new Path(bonsai_path).stroke('gray', 2);

stage.addChild(p);