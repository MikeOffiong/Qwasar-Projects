def my_roman_numerals_converter(num)
    # Create a hash with the Roman equivalents of decimal values
    roman_numerals = {
        1000 => "M",
        900 => "CM",
        500 => "D",
        400 => "CD",
        100 => "C",
        90 => "XC",
        50 => "L",
        40 => "XL",
        10 => "X",
        9 => "IX",
        5 => "V",
        4 => "IV",
        1 => "I",
    }

    result = ""
    # Iterate through the hash and append the Roman numeral to the result string
    roman_numerals.each do |key, value|
        while num >= key
            result += value
            num -= key
        end
    end

    result
end