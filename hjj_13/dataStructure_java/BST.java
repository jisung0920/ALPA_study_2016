
public class BST {
	private Node root;
	
	private class Node{
		private int key;
		private Node left_child;
		private Node right_child;
		private Node parent;
		Node(int key){
			this.key = key;
		}
	}
	
	public void insert(int key){
		// 1. there is no key.
		if(this.search(key) != null){
			System.out.println(key + " is already in the tree");
			return;
		}
		Node newNode = new Node(key);	// assume the data is same as key
		
		// 2. root is null.
		if(root==null) {
			root = newNode;
			root.parent = null;
			return;
		}
		Node tmp = root;
		Node pnt = null;
		while(true) {
			pnt = tmp;
			if(key<tmp.key){
				tmp = tmp.left_child;
				if(tmp==null){
					pnt.left_child = newNode;
					newNode.parent = pnt;
					return;
				}
			}
			else{
				tmp = tmp.right_child;
				if(tmp == null){
					pnt.right_child = newNode;
					newNode.parent = pnt;
					return;
				}
			}
		}
		
	}

	public void delete(int key){
		if(this.search(key) == null){
			System.out.println("There is no key in the tree");
			return;
		}
		Node tmp1 = root;
		Node pTmp1 = root;
		int check1 = 0;				//왼쪽 차일드로 갔는 지, 오른쪽 차일드로 갔는지 혹은 root에 남아있는지 확인하기위한 변수
		Node tmp2;
		Node pTmp2;

		while(true){ 				//지우는 노드 찾는 반복문
			if(key == tmp1.key)  
				break;
			else if(key<tmp1.key){
				pTmp1 = tmp1;
				tmp1 = tmp1.left_child;
				check1 = 1;			//왼쪽으로 가면 1
			}
			else if(key>tmp1.key){
				pTmp1 = tmp1;
				tmp1 = tmp1.right_child;
				check1 = 2;			//오른쪽으로 가면 2
			}
		}
		
		if(tmp1.left_child == null && tmp1.right_child == null){		//자식 노드가 없는 경우
			if(check1 == 1){
				pTmp1.left_child = null;
				tmp1.parent = null;
			}
			else{
				pTmp1.right_child = null;
				tmp1.parent = null;
			}
		}
		else if(tmp1.left_child != null && tmp1.right_child != null){	//자식 노드가 왼쪽,오른쪽 모두 있는 경우
			tmp2 = tmp1.left_child;					//왼쪽 노드로 tmp2지정
			pTmp2 = tmp1;							//부모 노드도 지정
			while(tmp2.right_child != null){		//왼쪽에서 가장 큰 값 찾는 반복문
					pTmp2 = tmp2;
					tmp2 = tmp2.right_child;
				}
			if(pTmp2 == tmp1){						//지우는 노드가 초기 노드와 높이가 1차이 나는 경우
				if(check1 == 1)
					pTmp1.left_child = tmp2;
				else
					pTmp2.right_child = tmp2;
				tmp2.right_child = tmp1.right_child;
				tmp2.parent = tmp1.parent;
				tmp1 = null;
			}
			else{
				pTmp2.right_child = tmp2.left_child;
				tmp2.left_child = tmp1.left_child;
				tmp2.right_child = tmp1.right_child;
				tmp2.parent = tmp1.parent;
				if(check1 == 0)						//check값이 변하지 않으면, 지우는 값이 root인 경우다
					root = tmp2;
				else if(check1 == 1)
					pTmp1.left_child = tmp2;
				else
					pTmp1.right_child = tmp2;
				tmp1 = null;
			}
		}
		else{										//차일드가 둘 중 하나만 존재 하는 경우
			if(tmp1.left_child != null){			//지우는 노드의 왼쪽 차일드만 있는 경우
				if(check1 == 1){
					pTmp1.left_child = tmp1.left_child;
					tmp1.left_child.parent = pTmp1;
				}
				else{
					pTmp1.right_child = tmp1.left_child;
					tmp1.left_child.parent = pTmp1;
				}
			}
			else{									//지우는 노드의 오른쪽 차일드만있는는 경우
				if(check1 == 1){
					pTmp1.left_child = tmp1.right_child;
					tmp1.right_child.parent = pTmp1;
				}
				else{
					pTmp1.right_child = tmp1.right_child;
					tmp1.right_child.parent = pTmp1;
				}
			}
		}
	}
			
		

	public Node search(int key){
		Node tmp = root;
		while(true){
			if(tmp == null)
				return null;
			else if(key==tmp.key)
				return tmp;
			else if(key>tmp.key)
				tmp = tmp.right_child;
			else
				tmp = tmp.left_child;
		}
		
	}
	public void printPreorder(Node node){
		if(node != null){
			System.out.print(node.key+" ");
			printPreorder(node.left_child);
			printPreorder(node.right_child);
		}
	}
	public void printInorder(Node node){
		if(node != null){
			printInorder(node.left_child);
			System.out.print(node.key+" ");
			printInorder(node.right_child);
		}
	}
	public void printPostorder(Node node){
		if(node != null){
			printPostorder(node.left_child);
			printPostorder(node.right_child);
			System.out.print(node.key+" ");
			
		}
	}
	public Node getRoot(){
		return root;
	}
}
