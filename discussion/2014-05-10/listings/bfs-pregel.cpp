class BFS
    : public Vertex<double, void, double> {
public:
    virtual void Compute(MessageIterator* msgs) {
        double* parent_id;
        double my_id;
        if (superstep() == 1) {                   // the 1st iteration
            if (isRoot(vertex_id())) {            // if i'm BFS root
                my_id = id2double(vertex_id());   // get my id
                parent_id = MutableValue();       // set my parent
                *parent_id = my_id;               // root is itself's parent
                SendMessageToAllNeighbors(my_id); // send my id to all successors
            }
            VoteToHalt();                 // halt until my predecessors wake me up
        } else {                          // normal iteration
            parent_id = MutableValue();
            *parent_id = iter.GetValue(); // select the 1st message as my parent
            my_id = id2double(vertex_id());
            SendMessageToAllNeighbors(my_id);
            VoteToHalt();                 // halt forever
        }
    }
}
