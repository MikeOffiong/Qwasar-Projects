class MySelectQuery 
    def initialize(csv_content)
        # Split the csv contents into lines
        @lines = csv_content.split("\n")
        # Split the first line (column names) into an array
        @column_names = @lines[0].split(',')
    end

    def where(column_name, criteria)
        # Find the index of the column with the given name
        column_index = @column_names.index(column_name)
        # Initialize an empty array to store the matching lines 
        matching_lines = []
        # Iterate through each line in the csv
        @lines[1..-1].each do |line|
            # Split the line into an array of values
            values = line.split(',')
            # If the value in the column with the given name matches the criteria, 
            # add the line to the array of matching lines.
            matching_lines << line if values[column_index] == criteria
        end
        # Return the array of matching lines
        matching_lines
    end

    def select(column_names)
        # Find the indices of the column with the given lines
        column_indices = column_names.map { |name| @column_names.index(name) }
        # Initialize an empty array to store the selected lines
        selected_lines = []
        # Iterate through each line in the csv
        @lines[1..-1].each do |line|
            # Split the line into an array of values
            values = line.split(',')
            # Initialize an empty array to store the selected values
            selected_values = []
            # Iterate through each column index
            column_indices.each do |index|
                selected_values << values[index]
            end
            # Join the array of selected values into a string and add it to the array of selected lines
            selected_lines << selected_values.join(',')
        end
        # Return the array of selected lines
        selected_lines
    end

    def sort(column_name, order = 'asc')
        # Find the index of the column with the given name
        column_index = @column_names.index(column_name)
        # Sort the lines by the value in the column with the given name
        @lines[1..-1] = @lines[1..-1].sort do |a, b|
            a_value = a.split(',')[column_index]
            b_value = b.split(',')[column_index]
            if order = 'asc'
                a_value < b_value ? -1 : a_value > b_value ? 1 : 0
            else
                a_value > b_value ? -1 : a_value < b_value ? 1 : 0
            end
        end
    end
end