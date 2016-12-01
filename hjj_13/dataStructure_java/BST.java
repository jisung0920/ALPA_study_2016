
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
		int check1 = 0;				//���� ���ϵ�� ���� ��, ������ ���ϵ�� ������ Ȥ�� root�� �����ִ��� Ȯ���ϱ����� ����
		Node tmp2;
		Node pTmp2;

		while(true){ 				//����� ��� ã�� �ݺ���
			if(key == tmp1.key)  
				break;
			else if(key<tmp1.key){
				pTmp1 = tmp1;
				tmp1 = tmp1.left_child;
				check1 = 1;			//�������� ���� 1
			}
			else if(key>tmp1.key){
				pTmp1 = tmp1;
				tmp1 = tmp1.right_child;
				check1 = 2;			//���������� ���� 2
			}
		}
		
		if(tmp1.left_child == null && tmp1.right_child == null){		//�ڽ� ��尡 ���� ���
			if(check1 == 1){
				pTmp1.left_child = null;
				tmp1.parent = null;
			}
			else{
				pTmp1.right_child = null;
				tmp1.parent = null;
			}
		}
		else if(tmp1.left_child != null && tmp1.right_child != null){	//�ڽ� ��尡 ����,������ ��� �ִ� ���
			tmp2 = tmp1.left_child;					//���� ���� tmp2����
			pTmp2 = tmp1;							//�θ� ��嵵 ����
			while(tmp2.right_child != null){		//���ʿ��� ���� ū �� ã�� �ݺ���
					pTmp2 = tmp2;
					tmp2 = tmp2.right_child;
				}
			if(pTmp2 == tmp1){						//����� ��尡 �ʱ� ���� ���̰� 1���� ���� ���
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
				if(check1 == 0)						//check���� ������ ������, ����� ���� root�� ����
					root = tmp2;
				else if(check1 == 1)
					pTmp1.left_child = tmp2;
				else
					pTmp1.right_child = tmp2;
				tmp1 = null;
			}
		}
		else{										//���ϵ尡 �� �� �ϳ��� ���� �ϴ� ���
			if(tmp1.left_child != null){			//����� ����� ���� ���ϵ常 �ִ� ���
				if(check1 == 1){
					pTmp1.left_child = tmp1.left_child;
					tmp1.left_child.parent = pTmp1;
				}
				else{
					pTmp1.right_child = tmp1.left_child;
					tmp1.left_child.parent = pTmp1;
				}
			}
			else{									//����� ����� ������ ���ϵ常�ִ´� ���
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
