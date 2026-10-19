struct cmp {
    bool operator()(const task& a, const task& b) {
        return a.priority > b.priority;
    }
};