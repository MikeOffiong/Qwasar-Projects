function my_levenshtein (string1, string2) {

    if(string1.length !== string2.length) return -1;

    let diff = "";
    string2.split('').forEach(function (val, i) {
        if (val != string1[i]) diff += val;
    });
    return diff.length;

}

//console.log(my_levenshtein(string1 && string2));
