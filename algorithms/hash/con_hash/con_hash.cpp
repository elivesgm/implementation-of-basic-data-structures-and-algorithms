// file: consistent hash

#define NODE_IDEN_LEN 64
#defien NODE_NUM      5
#define uint unsigned int

typedef struct Node {
    char   iden[NODE_IDEN_LEN]; //name
    uint   replica_num;
} NODE_S;

typedef struct vNode {
    uint     key;
    NODE_S*  Node;
}VNODE_S;

struct NODE_S g_nodes[NODE_NUM];



void conhash_set_node(NODE_S* node, const char* iden, uint replica_num) {
    if (node) {
        strncpy(node->iden, iden, sizeof(iden) - 1);
        node->replica_num = replica_num;
    }
}

void conhash_set_node_proc() {
    conhash_set_node(&g_nodes[0], "VM-0", 2);
    conhash_set_node(&g_nodes[1], "VM-1", 5);
    conhash_set_node(&g_nodes[2], "VM-2", 4);
    conhash_set_node(&g_nodes[3], "VM-3", 2);
    conhash_set_node(&g_nodes[4], "VM-4", 1);
}


void conhash_add_vnode(std::map<uint, NODE_S>&v_node_ring, NODE_S* pnode) {
    uint hash_key;
    char node_iden[NODE_IDEN_LEN];
    if (pnode) {
        for (int i = 0; i < pnode->replica_num; ++i) {
            snprintf(node_iden, NODE_IDEN_LEN, "%s-%03d", pnode->iden, i);
            std::string node_iden_string(node_iden);
            hash_key = std::hash<std::string>strhash(node_iden_string);
            v_node_ring[hash_key] = *pnode;
        }
    }
}

void conhash_add_vnode_proc(std::map<uint, NODE_S>&v_node_ring) {
    conhash_add_vnode(v_node_ring, &g_nodes[0]);
    conhash_add_vnode(v_node_ring, &g_nodes[1]);
    conhash_add_vnode(v_node_ring, &g_nodes[2]);
    conhash_add_vnode(v_node_ring, &g_nodes[3]);
    conhash_add_vnode(v_node_ring, &g_nodes[4]);
}

void conhash_del_vnode(std::map<uint, NODE_S>&v_node_ring, uint hash_key) {
    v_node_ring.erase(hash_key);
}

void conhash_del_node(std::map<uint, NODE_S>&v_node_ring, NODE_S* pnode) {
    uint hash_key;
    char node_iden[NODE_IDEN_LEN];
    if (pnode) {
        for (int i =  0; i < pnode->replica_num; ++i) {
            snprintf(node_iden, NODE_IDEN_LEN, "%s-%03d", pnode->iden, i);
            std::string node_iden_string(node_iden);
            hash_key = std::hash<std::string>strhash(node_iden_string);
            conhash_del_vnode(v_node_ring, hash_key);
        }
    }
}

void conhash_del_node_proc(std::map<uint, NODE_S>&v_node_ring) {
    conhash_del_node(v_node_ring, &g_nodes[2]); // for test
}

NODE_S conhash_lookup(std::map<uint, NODE_S>&v_node_ring, std::key_string) {
    uint hash_key = std::hash<std::string>strhash(key_string);
    if (v_node_ring.empty()) {
        return NULL;
    }
    else {
        auto itr = v_node_ring.upper_bound(hash_key); //获取环上下一个虚节点
        if (itr == v_node_ring.end()) { 
            itr = v_node_ring.begin(); //形成环
        }
        return itr->second;
    }
}

int main()
{
    std::map<uint, NODE_S>v_node_ring;

    //prepare node ring
    conhash_set_node_proc();
    conhash_add_vnode_proc(v_node_ring);

    //test
    string str("IP1");
    printf("<%s>: test for %s", __FUNCTION__, str);
    
    NODE_S node = conhash_lookup(v_node_ring, str);



}