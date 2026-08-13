 /* //apde string ne as charcter nahii but individual part tarike joi shakay chee atla mate j apde trversal darmiyan teno use karishu sarakhii rite
       //string na badha j consecutive group mathii j maximum frequency valo character find karoo jyare aa charcter malli jay tyar pachii maximum length ne find karo sarakhii rite 
       //SEGMENT TREE ae normally min/max/sum jevii values ne store karine ape chee in Range Query
       //but for segment apde 3 information ne store karine rakhishu suppose segment "aaabb" and (1) Prefix :Segement ni starting ma  ani mate starting ma ketla same charcter chee te pan store karvuu padse 
      //(2) Suffix: Segment ni end ma ketla character same chee te pan store karvuu padse 
      //(3) Best: Segement ni andar longest consecutive same charcter ni ketli substring chee answer best=3
      //(4)Charcter: prefix/suffix kai charc ter na chee ae pan important cheee kem ke segment ne merge karva mate left charcter and right charcter pan usefuyl chee
      //  best=max(left.best,right.best);
      //best=max({left.best,right.best,left.suffix+right.suffix})
     // Merge Function :
     //Node L=left Child and Node R=right child 
     //first create Node res and we know that res.line=L.len+ R.len
    // res.leftChar=L.leftchar
    //res.rightChar=R.rightChar
    //have check karo ke 
    //if(L.rightChar==R.leftChar)   
   // left Segement no last ch and right no first same thay chee ke nahii 
   // res.best=max(L.best,R.best);
   (//but longest sequence ae simply completely inside left or completely inside right hoi shake chee atle j)
   //res.best=max(res.best,L.suffix+R.prefix);
   //it simply means ke res.best=max({L.best,R.best,L.suffix+R.prefix});

   //Have aa be edge cases ne dhyan ma rakhjo
   // jo res.prefix=L.prefix   hoy to 
   //if(L.prefix==L.len && L.rightChar==R.leftChar){
  // res.prefix=L.len+R.prefix;

  //Same for Suffix:
 // res.suffix==R.suffix
 //if(R.suffix==R.len && L.rightChar ==R.leftChar){
 //res.suffix=R.len+L.suffix;}
 //TC=O(N+KLOGN)
//HARD*/
class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = 0;
            pref = 0;
            suff = 0;
            best = 0;
            leftChar = '#';
            rightChar = '#';
        }

        Node(char c) {
            len = 1;
            pref = 1;
            suff = 1;
            best = 1;
            leftChar = c;
            rightChar = c;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len) {
                res.pref = a.len + b.pref;
            }

            if (b.suff == b.len) {
                res.suff = b.len + a.suff;
            }
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.assign(4 * n + 5, Node());

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
     
