function my_spaceship (space_craft) {
    x = 0;
    y = 0;
    orientation = "up";

    for(index = 0; index < space_craft.length; index++) {     
        if (space_craft[index] == "R" && orientation == "up") {
            orientation = "right";
        }
        else if(space_craft[index] == "R" && orientation == "down") {
            orientation = "left";
        }
        else if(space_craft[index] == "R" && orientation == "left") {
            orientation = "up";
        }
        else if(space_craft[index] == "R" && orientation == "right") {
            orientation = "down";
        }
        else if(space_craft[index] == "L" && orientation == "up") {
            orientation = "left";
        }
        else if(space_craft[index] == "L" && orientation == "down") {
            orientation = "right";
        }
        else if(space_craft[index] == "L" && orientation == "left") {
            orientation = "down";
        }
        else if(space_craft[index] == "L" && orientation == "right") {
            orientation = "up";
        }
        else if(space_craft[index] == "A" && orientation == "up") {
            y--;
        }
        else if(space_craft[index] == "A" && orientation == "down") {
            y++;
        }
        else if(space_craft[index] == "A" && orientation == "left") {
            x--;
        }
        else if(space_craft[index] == "A" && orientation == "right") {
            x++;
        }
    }
        return "{x: " + x + ", y: " + y + ", direction: " + "'" + orientation + "'" + "}";
    }
    //console.log(my_spaceship("AAAA"));