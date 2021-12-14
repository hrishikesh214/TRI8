#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iomanip>

#define debug(x) std::cout << std::endl \
                           << #x << ": " << x << std::endl;

#define EXTRA_SPACE 2

std::string generate_error(std::string err_str)
{
    return "\n[PrettyTable Error] " + err_str + "\n";
}

class PrettyTable
{
public:
    bool execution_wait;
    int cols, rows;
    int cursor_x, cursor_y;
    std::vector<std::string> header;
    std::vector<std::vector<std::string>> data;
    std::vector<int> col_width;

    PrettyTable(std::vector<std::string> _header)
    {
        execution_wait = false;
        header = _header;
        cols = _header.size();
        rows = 0;
        cursor_x = cursor_x = -1;

        bool unused_var = col_width.empty();
        for (int i = 0; i < cols; i++)
        {
            col_width.push_back(header[i].size() + EXTRA_SPACE);
        }
        adjust_col_width();
    }

    void adjust_col_width(int row_no = -1)
    {
        if (row_no == -1)
        {
            for (int i = 0; i < cols; i++)
            {
                if (header[i].size() + EXTRA_SPACE > col_width[i])
                {
                    col_width[i] = header[i].size() + EXTRA_SPACE;
                }
            }
        }
        else
        {
            for (int i = 0; i < cols; i++)
            {
                if (data[row_no][i].size() + EXTRA_SPACE > col_width[i])
                {
                    col_width[i] = data[row_no][i].size() + EXTRA_SPACE;
                }
            }
        }
    }

    std::string get_row_from_vector(std::vector<std::string> trow)
    {
        std::stringstream row;
        row << "|";
        int trow_size = trow.size();
        for (int i = 0; i < trow_size; i++)
        {
            row << std::setw(col_width[i]) << trow[i];
            i < trow_size - 1 && row << "| ";
        }
        row << "|";
        return row.str();
    }

    PrettyTable *add_row(std::vector<std::string> new_row)
    {
        if (execution_wait)
            return this;
        if (new_row.size() != cols)
        {
            std::cout << generate_error("Row size does not match header size") << std::endl;
            execution_wait = true;
            return this;
        }
        rows++;
        data.push_back(new_row);

        // adjusting as per row
        adjust_col_width(rows - 1);

        return this;
    }

    void print()
    {
        if (execution_wait)
            return;
        int total_width = accumulate(col_width.begin(), col_width.end(), 0) * 1.2;
        std::stringstream ss;
        // ss << "|" <<std::setw(total_width) << std::setfill('-') << ""<< "|" << std::endl;
        // add header
        ss << get_row_from_vector(header);
        // add rows
        for (int i = 0; i < data.size(); i++)
        {
            ss << std::endl;
            ss << get_row_from_vector(data[i]);
        }
        std::cout << std::endl
                  << ss.str() << std::endl
                  << std::endl;
    }

    PrettyTable *at(int x_pos, int y_pos)
    {
        cursor_x = x_pos;
        cursor_y = y_pos;
        return this;
    }

    PrettyTable *write(std::string new_value)
    {
        try
        {
            if (cursor_x == -1 || cursor_y == -1)
                throw generate_error("Cursor not set");
            data[cursor_x][cursor_y] = new_value;
            cursor_x = cursor_y = -1;
            return this;
        }
        catch (std::string e)
        {
            std::cout << e;
            execution_wait = true;
            return this;
        }
    }

    std::string read()
    {
        try
        {
            std::string new_value = "";
            if (cursor_x == -1 || cursor_y == -1)
                throw generate_error("Cursor not set");
            new_value = data[cursor_x][cursor_y];
            cursor_x = cursor_y = -1;
            return new_value;
        }
        catch (std::string e)
        {
            std::cout << e;
            execution_wait = true;
            return "NULL";
        }
    }

    void empty()
    {
        data.clear();
    }
};

int main()
{
    PrettyTable *table = new PrettyTable({"Name", "Age", "Height"});
    table
        ->add_row({"Hrishi", "20", "5'10"})
        ->add_row({"gg", std::to_string(10), "710"})
        ->print();

    table->at(0, 2)
        ->write("new val")
        ->at(1, 0)
        ->write("ggs")
        ->print();
    std::cout << "\nok: " << table->at(1, 2)->read() << std::endl;
    return 0;
}