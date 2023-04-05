#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

using namespace std;

class SinhVien{
private:
    uint8_t id;
    char tenHocSinh[20];
    char gioiTinhHocSinh[4];
    uint8_t tuoiHocSinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTrungBinh;
    char hocLucSinhVien[11];
public:
    SinhVien(const char ten [], const char gioiTinh [], const uint8_t tuoi,
             const double toan, const double ly, const double hoa);
    void setTenHocSinh(const char ten []);
    void setGioiTinh(const char gioiTinh[]);
    void setTuoiHocSinh(const uint8_t tuoi);
    void setDiemToan(const double toan);
    void setDiemLy(const double ly);
    void setDiemHoa(const double hoa);

    uint8_t getID();
    char *getTenHocSinh();
    char *getGioiTinh();
    uint8_t getTuoiHocSinh();
    double getDiemToan();
    double getDiemLy(); 
    double getDiemHoa();
    double getDiemTrungBinh();      
    char *getHocLuc();
    
};

SinhVien::SinhVien(const char ten [], const char gioiTinh [], const uint8_t tuoi,
                   const double toan, const double ly, const double hoa ) {
                    
                   
                    static uint8_t id = 100; 
                    SinhVien::id = id;
                    id++;
                    strcpy (SinhVien::tenHocSinh, ten);
                    strcpy (SinhVien::gioiTinhHocSinh,gioiTinh);
                    SinhVien::tuoiHocSinh = tuoi;
                    SinhVien::diemToan = toan ;
                    SinhVien::diemLy = ly ;
                    SinhVien::diemHoa = hoa;   
}
class Menu {
    private:
  //vector<object_type> variable_name;
    vector<SinhVien> DanhSachSinhVien;
    timKiemTheoID(uint8_t id);
    timKiemTheoTen(ten);
    timKiemTheoGioiTinh(gioitinh);
    timKiemTheoTuoi(tuoi);

    public:
        void ThemSinhVien();
        void capNhatThongTin();
        void XoaSinhVien();
        void TimKiem();
        void SapXepTheoGPA();
        void SapXepTheoTen();
        void HienThiDanhSach();
};
#define NHAP_THONG_TIN(noiDung, dinhDang ,bien, dieuKien) \
do {                                            \
    printf ("%s: " noiDung);                   \
    scanf (dinhDang, bien);                     \
}while (dieuKien)

void Menu::ThemSinhVien(){
    char ten [20];
    char gioiTinh [4];
    uint8_t tuoi;
    double diemToan;
    double diemLy;
    double diemHoa;
    int key;
    do {

    printf("vui long nhap thong tin sinh vien :\n");
    printf("Nhap ten: ");
    scanf("%s",ten);
    printf("Nhap Gioi tinh: (Nam / Nu) ");
    scanf("%s",gioiTinh);
    NHAP_THONG_TIN(" Nhap tuoi (18 - 100)"   , "%hu", &tuoi,tuoi <18 || tuoi >100);
    NHAP_THONG_TIN(" Nhap diem toan (0 - 10)", "%lf", &diemToan, diemToan <0 || diemToan >10);
    NHAP_THONG_TIN(" Nhap diem ly   (0 - 10)", "%lf", &diemLy,   diemLy   <0 || diemLy   >10);
    NHAP_THONG_TIN(" Nhap diem hoa  (0 - 10)", "%lf", &diemHoa,  diemHoa  <0 || diemHoa  >10);
    
    SinhVien sv (ten, gioiTinh , tuoi , diemToan , diemLy , diemHoa);

    DanhSachSinhVien.push_back(sv);
    printf("Nhan 1 de tiep tuc them sinh vien \n");
    printf("Nhan bat ky de thoat tro ve menu \n");
    scanf ("%d", &key);
    }
    while (key ==1);

}

void Menu::HienThiDanhSach(){
    printf("Hien thi danh sach sinh vien\n");
    printf("ID\tTen\tGioiTinh\tTuoi\tToan\tLy\tHoa\tGPA\tHocLuc\t\n");
    printf("-------------------------------------------------------------------------------------\n");
    for (SinhVien sv : DanhSachSinhVien)
    {
        printf("%d\t%s\t%s\t\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%s\t\n",
        sv.getID(),sv.getTenHocSinh(),sv.getGioiTinh(),sv.getTuoiHocSinh(),
        sv.getDiemToan(),sv.getDiemLy(),sv.getDiemHoa(),sv.getDiemTrungBinh(),sv.getHocLuc());
    }
}


// hàm này sẽ cập nhật thôn tin sinh viên  
// yêu cầu người dùng nhập id sinh vân cần chỉnh sửa
// đưa ra 1 menu cho người dùng lựa chọn thông tin nào cần chỉnh sửa 
// người dùng chỉnh sử và cập nhật thông tin 
void Menu::capNhatThongTin(){

int id;
int choice;
printf("Nhap ID sinh viên bạn muốn chỉnh sửa\n");
scanf ("%d",&id);
for (SinhVien& sv : DanhSachSinhVien ) 
{
    //sử dụng đối tượng sv để gọi phương thức getID() và trả về giá trị của thuộc tính ID sau đó so sánh với id vừa nhập từ bàn phím
    if (sv.getID() == id) {
        printf("Nhap thong tin moi cho sinh vien co ID %d:\n", id);
            printf("1. Ten hoc sinh\n");
            printf("2. Gioi tinh\n");
            printf("3. Tuoi hoc sinh\n");
            printf("4. Diem toan\n");
            printf("5. Diem ly\n");
            printf("6. Diem hoa\n");
            printf("Chon thong tin muon chinh sua (1-6): ");
        }
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            char ten[20];
            printf("Nhap ten moi: ");
            scanf("%s", ten);
            sv.setTenHocSinh(ten);
            break;
        case 2:
            char gioiTinh [4];
            printf("Nhap Gioi tinh: ");
            scanf("%s",gioiTinh);
            sv.setGioiTinh(gioiTinh);
            break;
        case 3:
            uint8_t Tuoi;
            printf("Nhap Tuoi: ");
            scanf("%d",&Tuoi);
            sv.setTuoiHocSinh(Tuoi);
            break;
        case 4:
            double DiemToan;
            printf("Nhap Diem Toan : ");
            scanf("%lf",&DiemToan);
            sv.setDiemToan(DiemToan);
            break;
        case 5:
            double DiemLy;
            printf("Nhap Diem Ly : ");
            scanf("%lf",&DiemLy);
            sv.setDiemLy(DiemLy);
            break;
        case 6:
            double DiemHoa;
            printf("Nhap Diem Hoa : ");
            scanf("%lf",&DiemHoa);
            sv.setDiemHoa(DiemHoa);
            break;
        default:
            break;
        }
        double GPA;
        char hocLuc[15]; 
        break;
        return;
    }
    printf("Khong tim thay sinh vien co ID %d trong danh sach.\n", id);

}




   

//Hàm này có thể yêu cầu người dùng nhập ID của sinh viên cần xóa khỏi danh sách 
//sau đó xóa sinh viên đó khỏi danh sách.

void Menu::XoaSinhVien(){
int id;
int choice;

printf("Nhap ID sinh viên bạn muốn xoa\n");
scanf ("%d",&id);

//duyệt,truy cập các phần tử của vector thông qua các con trỏ hoặc iterators   
//bắt đầu từ phần tử đầu tiên .begin() kết thúc tạo .end()
int i =0;
for (SinhVien sv : DanhSachSinhVien)
//decltype(DanhSachSinhVien)::iterator it = DanhSachSinhVien.begin();
    {
        //if (sv.getID() == id) 
        //if (*it).getID()==id //lấy phần tử tại vị trí hiện tại của iterator it và gọi phương thức getID() của đối tượng sinh viên tương ứng để lấy giá trị ID
        if (sv.getID() == id)//kiểm tra xem phần tử tại vị trí hiện tại của iterator có trùng với ID sinh viên cần xóa hay không.
            
            {
                DanhSachSinhVien.erase(DanhSachSinhVien.begin()+i);
                printf("Da xoa sinh vien co ID %d khoi danh sach.\n", id);
                return;
            }
            i++;
    }
printf("Khong tim thay sinh vien co ID %d trong danh sach.\n", id);
}


enum type{
    ID = 1,
    TEN = 2,
    GIOI_TINH = 3,
    TUOI = 4 
}type;
//Hàm này có thể yêu cầu người dùng nhập thông tin để tìm kiếm sinh viên theo tên hoặc ID
//sau đó hiển thị kết quả tìm kiếm.
void Menu::TimKiem(){
int id;
char ten[20];
char gioitinh[4];
int tuoi;
int choice;
// hiển thị menu tùy chọn tìm kiếm
printf("1. Tim kiem theo ID hoc sinh\n");
printf("2. Tim kiem theo ten hoc sinh\n");
printf("3. Tim kiem theo gioi tinh\n");
printf("4. Tim kiem theo tuoi hoc sinh\n");
// kiểm tra lựa chọn của người dùng
scanf("%d", &choice);
char key [9];

do
{
    switch (choice)
{
    case ID:
    printf("Nhap ID sinh vien ban muon tim kiem: ");
    scanf("%d", &id);
    timKiemTheoID(id);
    break;

    case TEN:
    printf("Nhap ten sinh vien ban muon tim kiem: ");
    scanf("%s", &ten);
    timKiemTheoTen(ten);
    break;

    case GIOI_TINH:
    printf("Nhap gioi tinh sinh vien ban muon tim kiem (nam/nu): ");
    scanf("%s", gioitinh);
    timKiemTheoGioiTinh(gioitinh);
    break;

    case TUOI:
    printf("Nhap tuoi sinh vien ban muon tim kiem: ");
    scanf("%d",&tuoi);
    timKiemTheoTuoi(tuoi);
    break;

    default:
    printf("Nhap khong dung vui long nhap lai");
    break;
    
} while ( key != (ID || TEN || GIOI_TINH || TUOI) );


}

// duyệt qua danh sách sinh viên và hiển thị thông tin sinh viên thỏa mãn điều kiện tìm kiếm

for (SinhVien sv : DanhSachSinhVien)
    {
        if ( //nếu chọn lựa chọn 1 và id nguoi dung nhap bang id co trong danh sách hoặc
             //nếu chọn lựa chọn 2 và ten nguoi dung nhap giong ten co trong danh sách hoặc
             //nếu chọn lựa chọn 3 và gioitinh nguoi dung nhap giong gioi co trong danh sách hoặc
             //nếu chọn lựa chọn 4 và tuoi nguoi dung nhap giong tuoi co trong danh sách 
            (choice == 1 && sv.getID() == id) || 
            (choice == 2 && strcmp(sv.getTenHocSinh(), ten) == 0) || 
            (choice == 3 && strcmp(sv.getGioiTinh(), gioitinh) == 0) || 
            (choice == 4 && sv.getTuoiHocSinh() == tuoi)) 
        {
            //hien thị ra danh cách dựa vào các diều kiện ở trên
            printf("%d\t%s\t%s\t\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
            sv.getID(), sv.getTenHocSinh(), sv.getGioiTinh(), sv.getTuoiHocSinh(),
            sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(),
            sv.getDiemTrungBinh(), sv.getHocLuc());
        }
    }
    printf("Khong tim thay sinh vien trong danh sach.\n");
}   
//Hàm này sắp xếp danh sách sinh viên theo điểm trung bình  
//ý tưởng lấy gpa  ra cho vao 1 mang vector sau dó 
//có 2 lựa chọn 1 là theo chiều giảm dần
//2 là theo chiều tăng đần
void Menu::SapXepTheoGPA() {
    //Lấy số lượng sinh viên từ danh sách
    int n = DanhSachSinhVien.size();
    //Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng
    for (int i = 0; i < n - 1; i++) {
        //Duyệt vòng lặp bên trong từ vị trí tiếp theo của vòng lặp bên ngoài đến vị trí cuối cùng.
        for (int j = i + 1; j < n; j++) {
            //so sánh điểm trung bình từ 
            if (DanhSachSinhVien[i].getDiemTrungBinh() < DanhSachSinhVien[j].getDiemTrungBinh()) {

                // Thực hiện hoán đổi vị trí của hai sinh viên
                SinhVien temp = DanhSachSinhVien[i];
                DanhSachSinhVien[i] = DanhSachSinhVien[j];
                DanhSachSinhVien[j] = temp;

            }
        }
    }
    // for (SinhVien sv : DanhSachSinhVien)
    // {
    //     printf("%d\t%s\t%s\t\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
    //     sv.getID(), sv.getTenHocSinh(), sv.getGioiTinh(), sv.getTuoiHocSinh(),
    //     sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(),
    //     sv.getDiemTrungBinh(), sv.getHocLuc());
    // }

}


//Hàm này sắp xếp danh sách sinh viên theo tên theo thứ tự tăng dần bảng chữ cái 
void Menu::SapXepTheoTen() {
//Lấy số lượng sinh viên từ danh sách
int n = DanhSachSinhVien.size();
//Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng
for (int i = 0; i < n - 1; i++) {
    //Duyệt vòng lặp bên trong từ vị trí tiếp theo của vòng lặp bên ngoài đến vị trí cuối cùng.
    for (int j = i + 1; j < n; j++) {
        //So sánh tên của hai sinh viên ở hai vị trí hiện tại của vòng lặp bên ngoài và bên trong
        //hàm strcmp() để so sánh chuỗi ký tự của hai tên.
        // Nếu tên của sinh viên ở vị trí j đứng trước tên sinh viên ở vị trí i
        if (strcmp(
                    DanhSachSinhVien[i].getTenHocSinh(),
                    DanhSachSinhVien[j].getTenHocSinh()
                  ) > 0) {
            //// Thực hiện hoán đổi vị trí của hai sinh viên
            SinhVien temp = DanhSachSinhVien[i];
            DanhSachSinhVien[i] = DanhSachSinhVien[j];
            DanhSachSinhVien[j] = temp;
            }
        }
    }
}










uint8_t SinhVien::getID(){
   return id;
}
void SinhVien::setTenHocSinh(const char ten[])
{
    strcpy(tenHocSinh, ten);
}
char* SinhVien::getTenHocSinh()
{
    return tenHocSinh; 
}
void SinhVien::setGioiTinh(const char gioiTinh[]) {
    if ((strcmp("Nam", gioiTinh) != 0) && (strcmp("Nu", gioiTinh) != 0) && (strcmp("nu", gioiTinh) != 0) && (strcmp("nam", gioiTinh) != 0)) {
        printf("Gioi tinh khong hop le\n");
    } else {
        strcpy(gioiTinhHocSinh, gioiTinh);
    }
}

char* SinhVien::getGioiTinh()
{
    return gioiTinhHocSinh;
}

void SinhVien::setTuoiHocSinh(const uint8_t tuoi){
        tuoiHocSinh = tuoi;
}
uint8_t SinhVien::getTuoiHocSinh(){
    return tuoiHocSinh;
}
void SinhVien::setDiemToan(const double toan){
    diemToan = toan;
}
double SinhVien::getDiemToan(){
    return diemToan;
}
void SinhVien::setDiemLy(const double ly){
    diemLy = ly;
}
double SinhVien::getDiemLy(){
    return diemLy;
}
void SinhVien::setDiemHoa(const double hoa){
    diemHoa = hoa;
}
double SinhVien::getDiemHoa(){
    return diemHoa;
}
double SinhVien::getDiemTrungBinh(){
    return (diemToan+diemHoa+diemLy)/3;
}


char* SinhVien::getHocLuc() {
    char* hocLuc = new char[11];

    if (getDiemTrungBinh()>= 8.0) {
        strcpy(hocLuc, "Gioi");
    } else if (getDiemTrungBinh()  >= 6.5 ) {
        strcpy(hocLuc, "Kha");
    } else if (getDiemTrungBinh() >= 5.0 ) {
        strcpy(hocLuc, "Trung Binh");
    } else {
        strcpy(hocLuc, "Yeu");
    }
    return hocLuc;
}
// char* SinhVien::getHocLuc() {
//     char hocLuc[11];
//     double gpa = SinhVien::getDiemTrungBinh();
//     if (gpa>= 8.0) {
//         strcpy(hocLuc, "Gioi");

//     } else if (gpa>= 6.5 ) {
//         strcpy(hocLuc, "Kha");

//     } else if (gpa>= 5.0 ) {
//         strcpy(hocLuc, "Trung Binh");

//     } else {
//         strcpy(hocLuc, "Yeu");
//     }
//     return hocLuc;
// }




int main(int argc, char const *argv[])
{

Menu mn1;

int choice;
    
    do {
        printf ("Chon mot trong cac chuc nang sau:\n");
        printf ("1. Them sinh vien\n");
        printf ("2. Cap nhat thong tin sinh vien\n");
        printf ("3. Xoa sinh vien\n");
        printf ("4. Tim kiem sinh vien\n");
        printf ("5. Sap Xep Theo GPA\n");
        printf ("6. Sap Xep Theo Ten\n");
        printf ("7. Hien thi danh sach sinh vien\n");
        printf ("8. Thoat\n");


        scanf("%d",&choice);
    
        switch(choice) {
            case 1:
                mn1.ThemSinhVien();
                break;
            case 2:
                mn1.capNhatThongTin();
                break;
            case 3:
                mn1.XoaSinhVien();
                break;
            case 4:
                mn1.TimKiem();
                
                break;
            case 5:
                mn1.SapXepTheoGPA();
                mn1.HienThiDanhSach();
                break;
            case 6:
                mn1.SapXepTheoTen();
                mn1.HienThiDanhSach();
                break;
            case 7:
                mn1.HienThiDanhSach();
                break;
            case 8:
                printf ("Ket thuc chuong trinh.\n");
                return 0;
            default:
                "Vui long chon mot lua chon hop le.\n";
                break;
        }
    } while(choice != 8);
    
    return 0;
}
