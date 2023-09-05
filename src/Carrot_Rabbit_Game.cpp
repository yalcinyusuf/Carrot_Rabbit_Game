//============================================================================
// Name        : Carrot_Rabbit_Game.cpp
// Author      : Yusuf
// Date     : 19.08.2023
// Description : Carrot Rabbit Game in C++
//============================================================================

#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace cv;
using namespace std;

// Tavşanın mevcut pozisyonunu saklamak için global değişken
int rabbit_x, rabbit_y;

// Mouse callback function
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_MOUSEMOVE)
    {
        rabbit_x = x;
        rabbit_y = y;
    }
}

int main()
{
    srand(time(0));

    // Oyunun görüntü yüksekliği ve genişliği belirleme ve bu boyutlarda bir görüntü (scene) oluşturma
    int width = 1200, height = 900;
    Mat scene(height, width, CV_8UC3);

    //Oyun zemini olarak kullanılacak arka plan görüntüsü yükleme ve boyutu sahnenin boyutuna ayarlama
    Mat background = imread("data/soil.png");
    resize(background, background, Size(width, height));

    Mat carrot_image = imread("data/carrot.png");
    Mat rabbit_image = imread("data/rabbit.png");
    if (carrot_image.empty() || rabbit_image.empty()) {
        cerr << "Error: Cannot load images" << endl;
        return -1;
    }

    int score = 0;
    int carrot_x = rand() % width, carrot_y = rand() % height;
    int carrot_speed = (rand() % 8) + 4;
    int carrot_angle = rand() % 360;

    int rabbit_size = 30;
    rabbit_x = width / 2, rabbit_y = height - 50;

    // Set mouse callback function
    namedWindow("Carrot Rabbit Game");
    setMouseCallback("Carrot Rabbit Game", onMouse);

    //Ana oyun döngüsü başlar.
    while (true) {

		//Arka plan görüntüsü sahneye kopyalama
		background.copyTo(scene);
		//Havuçun hareketini hesaplama
		carrot_x += static_cast<int>(carrot_speed * cos(carrot_angle * CV_PI / 180));
		carrot_y += static_cast<int>(carrot_speed * sin(carrot_angle * CV_PI / 180));
		//Havuçun ekran sınırlarına çarpma durumunu kontrol etme
		if (carrot_x <= 15 || carrot_x >= width-15) {
			carrot_angle = 180 - carrot_angle;
			carrot_x = max(15, min(width-15, carrot_x));
		}
		if (carrot_y <= 30 || carrot_y >= height-30) {
			carrot_angle = -carrot_angle;
		    carrot_y = max(30, min(height-30, carrot_y));
		}

        // Tavşan resmi sahne üzerine çizme
        int rabbit_width = rabbit_image.cols;
        int rabbit_height = rabbit_image.rows;
        Rect rabbit_roi(rabbit_x - rabbit_width / 2, rabbit_y - rabbit_height / 2, rabbit_width, rabbit_height);

        if (rabbit_roi.x >= 0 && rabbit_roi.y >= 0 && rabbit_roi.x + rabbit_roi.width <= width && rabbit_roi.y + rabbit_roi.height <= height) {
            Mat rabbit_region = scene(rabbit_roi);
            rabbit_image.copyTo(rabbit_region);
        }

        // Havuç resmi sahne üzerine çizme
		int carrot_width = carrot_image.cols;
		int carrot_height = carrot_image.rows;
		Rect carrot_roi(carrot_x - carrot_width / 2, carrot_y - carrot_height / 2, carrot_width, carrot_height);

		if (carrot_roi.x >= 0 && carrot_roi.y >= 0 && carrot_roi.x + carrot_roi.width <= width && carrot_roi.y + carrot_roi.height <= height) {
		  Mat carrot_region = scene(carrot_roi);
		  carrot_image.copyTo(carrot_region);
		}
		// Eğer tavşan havucu yakalarsa, puan arttırılır ve yeni bir havuç rastgele pozisyon ve hızla yerleştirilir.
		double distance = sqrt(pow(carrot_x - rabbit_x, 2) + pow(carrot_y - rabbit_y, 2)); // Öklid uzaklığı
		if (distance < rabbit_size + carrot_width / 2) {
		  score++;
		  carrot_x = (rand() % width)+15;
		  if(carrot_x >=788)
		  {
			  carrot_x -= 15;
		  }
		  else if(carrot_x <=15)
		  {
			  carrot_x += 15;
		  }
		  carrot_y = (rand() % height);
		  if(carrot_y >=570)
		  {
			  carrot_y -= 30;
		  }
		  else if(carrot_y <=30)
		  {
			  carrot_y += 30;
		  }
		  carrot_speed = (rand() % 8) + 4;
		  carrot_angle = rand() % 360;
		}

		putText(scene, "Score: " + to_string(score), Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(255, 255, 255), 2);
        imshow("Carrot Rabbit Game", scene);
        if (waitKey(1) == 'q') {
            break;
        }
    }
    destroyAllWindows();
    return 0;
}
