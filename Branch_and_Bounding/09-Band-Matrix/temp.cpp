    Node(vector<int> rows, vector<int> cols, int n_fixed_rows, int n_fixed_cols, int bound, int order)
    {
        this->rows = rows;
        this->cols = cols;
        this->n_fixed_rows = n_fixed_rows;
        this->n_fixed_cols = n_fixed_cols;
        this->bound = bound;
        this->order = order;
    }