bool operator()(const Job &a, const Job &b)
    {
        return a.deadline < b.deadline;
    }