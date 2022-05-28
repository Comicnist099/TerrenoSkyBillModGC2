#ifndef _dxrr
#define _dxrr
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <d3dx10math.h>
#include "TerrenoRR.h"
#include "Camara.h"
#include "SkyDome.h"
#include "Billboard.h"
#include "ModeloRR.h"
#include "Water.h"
#include "XACT3Util.h"
#include "GUI.h"

class DXRR{	

private:
	int ancho;
	int alto;
public:	

	float Olas;

	bool CollisionONE(float v_px, float v_pz)
	{
		if ((v_pz > 274.007) && (v_pz < 280.88))
		{
			if ((v_px > -296.66) && (v_px < 301.93))
			{
				return true;

			}
		}

		if ((v_px > -296.66) && (v_px < 301.93))
		{
			if ((v_pz > 274.007) && (v_pz < 280.88))
			{
				return true;

			}
		}
		return false;

	}

	bool CollisionTWO(float v_px, float v_pz)
	{
		
		if ((v_pz > -292.56) && (v_pz < -287.29))
		{
			if ((v_px > -304.50) && (v_px < 299.83))
			{
				return true;

			}
		}

		if ((v_px > -304.50) && (v_px < 299.83))
		{
			if ((v_pz > -292.56) && (v_pz <-287.29))
			{
				return true;
			}
		}
		return false;

	}


	bool CollisionTHREE(float v_px, float v_pz)
	{

		if ((v_pz > -287) && (v_pz < 273))
		{
			if ((v_px > 291.01) && (v_px < 291.56))
			{
				return true;

			}
		}

		if ((v_px > 291.01) && (v_px < 291.56))
		{
			if ((v_pz > -287) && (v_pz < 273))
			{
				return true;
			}
		}
		return false;

	}
	bool CollisionFOUR(float v_px, float v_pz)
	{

		if ((v_pz > -287) && (v_pz < 273))
		{
			if ((v_px > -296.33) && (v_px <- 290.33))
			{
				return true;

			}
		}

		if ((v_px > -296.33) && (v_px < -290.33))
		{
			if ((v_pz > -287) && (v_pz < 273))
			{
				return true;
			}
		}
		return false;

	}



	HINSTANCE hInstance;
	HWND hWnd;

	D3D_DRIVER_TYPE driverType;
	D3D_FEATURE_LEVEL featureLevel;

	ID3D11Device* d3dDevice;
	ID3D11DeviceContext* d3dContext;
	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* backBufferTarget;

	ID3D11Texture2D* depthTexture;
	ID3D11DepthStencilView* depthStencilView;

	ID3D11DepthStencilState* depthStencilState;
	ID3D11DepthStencilState* depthStencilDisabledState;

	ID3D11BlendState *alphaBlendState, *commonBlendState;

	int frameBillboard;

	float animacionagua = 0.0f;



	TerrenoRR *terreno;
	SkyDome *skydome;
	BillboardRR *billboard;
	BillboardRR *billboard2;
	BillboardRR *billboard3;
	BillboardRR *billboard4;
	BillboardRR *billboard5;
	BillboardRR *billboard6;
	BillboardRR *billboard7;
	BillboardRR *billboard8;
	BillboardRR *billboard9;
	BillboardRR* billboard10;

	float time = 0;

	BillboardRR *Water;
	Camara *camara;


	ModeloRR* Colision;
	ModeloRR* Colision2;
	ModeloRR* Colision3;
	ModeloRR* Colision4;
	ModeloRR* Colision5;
	ModeloRR* Colision6;
	ModeloRR* Colision7;

	ModeloRR* Colision8;

	ModeloRR* Colision9;


	ModeloRR* Cofre;
	ModeloRR* PayasoModel;
	ModeloRR* PayasoModel2;
	ModeloRR* PayasoModel3;
	ModeloRR* PayasoModel4;

	ModeloRR* Vaca;
	ModeloRR* Vacapivot;

	ModeloRR* Circo;
	ModeloRR* Cabaña;
	ModeloRR* Cabaña2;

	ModeloRR* bote;
	ModeloRR* torre;
	ModeloRR* quack;
	ModeloRR* fuente;
	ModeloRR* lampara;
	ModeloRR* torrepiedra;

	ModeloRR* tren;
	ModeloRR* trenpivot;
	Agua* lake;

	int payasos = 0;

	bool Esta=false;
	bool Flag=false;
	bool Flag2=false;
	bool Flag3=false;
	bool Flag4=false;
	bool Flag5=false;

	GUI* Explosion;
	GUI* Linea;


	GUI* Win;
	GUI* GameOver;


	GUI* timegui;


	GUI* payakill;
	GUI* payakill2;
	GUI* payakill3;
	GUI* payakill4;
	GUI* payakill5;
	
	GUI* payakillD;
	GUI* payakillD2;
	GUI* payakillD3;
	GUI* payakillD4;
	GUI* payakillD5;



	float izqder;
	float arriaba;
	float vel;
	float velSides;
	float modelRotation;
	bool breakpoint;
	bool firstPerson;
	bool Vehiculo;
	bool once;

	vector2 uv1[32];
	vector2 uv2[32];
	vector2 uv3[32];
	vector2 uv4[32];

	D3DXVECTOR3 wata = { 0,0,0 };
	XACTINDEX cueIndex;
	CXACT3Util m_XACT3;
	D3DXVECTOR3 posCam;

    DXRR(HWND hWnd, int Ancho, int Alto)
	{


		breakpoint = false;
		frameBillboard = 0;
		ancho = Ancho;
		alto = Alto;
		driverType = D3D_DRIVER_TYPE_NULL;
		featureLevel = D3D_FEATURE_LEVEL_11_0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
		IniciaD3D(hWnd);
		izqder = 0;
		arriaba = 0;
		billCargaFuego();
		camara = new Camara(D3DXVECTOR3(100,80,150), D3DXVECTOR3(0,80,0), D3DXVECTOR3(0,1,0), Ancho, Alto);




		terreno = new TerrenoRR(600, 600, d3dDevice, d3dContext);
		skydome = new SkyDome(32, 32, 700.0f, &d3dDevice, &d3dContext, L"SkyDome.jpg", L"SkyDome_Night.jpg");

		billboard = new BillboardRR(L"arbol.png",L"arbol.png", d3dDevice, d3dContext, 10);
		billboard2 = new BillboardRR(L"arbolito.png",L"arbolito.png", d3dDevice, d3dContext, 10);


		billboard3 = new BillboardRR(L"Arbol2.png",L"Arbol2.png", d3dDevice, d3dContext, 12);

		billboard4 = new BillboardRR(L"Hola.png",L"Hola.png", d3dDevice, d3dContext, 6);
		billboard5 = new BillboardRR(L"Assets/Billboards/boi2.png",L"Assets/Billboards/boi2.png", d3dDevice, d3dContext, 6);
		billboard6 = new BillboardRR(L"Assets/Billboards/boi3.png",L"Assets/Billboards/boi3.png", d3dDevice, d3dContext, 6);
		billboard7 = new BillboardRR(L"Assets/Billboards/boi4.png",L"Assets/Billboards/boi4.png", d3dDevice, d3dContext, 6);
		billboard8 = new BillboardRR(L"Assets/Billboards/boi5.png",L"Assets/Billboards/boi5.png", d3dDevice, d3dContext, 6);
		billboard9 = new BillboardRR(L"Assets/Billboards/boi6.png",L"Assets/Billboards/boi6.png", d3dDevice, d3dContext, 9);
		billboard10 = new BillboardRR(L"Assets/Billboards/billboard.png", L"Assets/Billboards/billboard.png", d3dDevice, d3dContext, 6);

		Water = new BillboardRR(L"Assets/Billboards/Water.jpg", L"Assets/Billboards/WaterNormal.png", L"Assets/Billboards/WaterDisplacement.png",d3dDevice, d3dContext, 6);
		

		Colision = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", -170, 291, 90);

		//-----------------------------------------------------------------Modelos--------------------------------------------------------------------

		Cofre = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", 100, 0,20);
		PayasoModel = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", -70, 0,20);
		PayasoModel2 = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", 0, 0,20);
		PayasoModel3 = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", -70, -130,20);
		PayasoModel4 = new ModeloRR(d3dDevice, d3dContext, "Assets/paya/BIO-I_PC_N.P.C_Clown.obj", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_D.png", L"Assets/paya/BIO-I_PC_N.P.C_Clown_Body_M3.png", -275, 55,20);

		Circo = new ModeloRR(d3dDevice, d3dContext, "Assets/circo/circo.obj", L"Assets/circo/circo.png", L"Assets/circo/circoespecular.png", 100, 100, 40);
		Cabaña = new ModeloRR(d3dDevice, d3dContext, "Assets/cabaña/house.obj", L"Assets/cabaña/houseTex.jpg", L"Assets/cabaña/houseSpecular.jpg", 0, -180, 25);
		Cabaña2 = new ModeloRR(d3dDevice, d3dContext, "Assets/cabaña2/house2.obj", L"Assets/cabaña2/house2Tex.jpg", L"Assets/cabaña2/house2Tex.jpg", -119, -163, 35);

		bote = new ModeloRR(d3dDevice, d3dContext, "Assets/bote/BasuraNuevo.obj", L"Assets/bote/basuraamarilla.png", L"Assets/bote/basuraespecular.png", -188, -177, 10);
		torre = new ModeloRR(d3dDevice, d3dContext, "Assets/torre/torre.obj", L"Assets/torre/torreTex.jpg", L"Assets/torre/torreSpecular.jpg", -50, -240, 20);
		quack = new ModeloRR(d3dDevice, d3dContext, "Assets/pato/pato.obj", L"Assets/pato/patoTex.jpg", L"Assets/pato/patoSpecular.jpg", 40, 10, 10);
		fuente = new ModeloRR(d3dDevice, d3dContext, "Assets/Fuente/FuenteCorrect.obj", L"Assets/Fuente/fuentetextura.png", L"Assets/Fuente/fuenteespecular.png", 0, 150, 25);
		lampara = new ModeloRR(d3dDevice, d3dContext, "Assets/lampara/lamparaObjeto.obj", L"Assets/lampara/lamparaText.png", L"Assets/lampara/lamparaText.png", -50, 60, 10);


		Explosion = new GUI(d3dDevice, d3dContext, 3, 3, L"Explosion.png");
		Win	 = new GUI(d3dDevice, d3dContext, 2, 2, L"Win.jpg");
		GameOver = new GUI(d3dDevice, d3dContext, 2, 2, L"GameOver.jpg");

		Linea = new GUI(d3dDevice, d3dContext, 1, 2, L"Linea.png");



		timegui = new GUI(d3dDevice, d3dContext, 0.20, 0.20, L"time.png");


		payakill = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOL.png");
		payakill2 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOL.png");
		payakill3 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOL.png");
		payakill4 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOL.png");
		payakill5 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOL.png");

		payakillD = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOLD.png");
		payakillD2 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOLD.png");
		payakillD3 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOLD.png");
		payakillD4 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOLD.png");
		payakillD5 = new GUI(d3dDevice, d3dContext, 0.10, 0.10, L"clownLOLD.png");


		Vaca = new ModeloRR(d3dDevice, d3dContext, "Assets/vaca2/cow.obj", L"Assets/vaca2/cowSpecular.jpg", L"Assets/vaca2/cowSpecular.jpg", camara->posCam.x, camara->posCam.z, 1);

		Vacapivot = new ModeloRR(d3dDevice, d3dContext, "Assets/vaca/cow.obj", L"Assets/vaca/cowSpecular.jpg", L"Assets/vaca/cowSpecular.jpg", camara->posCam.x, camara->posCam.z, 1);


		trenpivot = new ModeloRR(d3dDevice, d3dContext, "Assets/cabra2/chicken.obj", L"Assets/cabra2/chicken.png", L"Assets/cabra2/chicken.png", camara->posCam.x, camara->posCam.z,1);
		tren = new ModeloRR(d3dDevice, d3dContext, "Assets/cabra/chicken.obj", L"Assets/cabra/chicken.png", L"Assets/cabra/chicken.png", camara->posCam.x, camara->posCam.z,1);


		
	}

	~DXRR()
	{
		LiberaD3D();
		m_XACT3.Terminate();
	}
	
	bool IniciaD3D(HWND hWnd)
	{
		this->hInstance = hInstance;
		this->hWnd = hWnd;

		//obtiene el ancho y alto de la ventana donde se dibuja
		RECT dimensions;
		GetClientRect(hWnd, &dimensions);
		unsigned int width = dimensions.right - dimensions.left;
		unsigned int heigth = dimensions.bottom - dimensions.top;

		//Las formas en como la pc puede ejecutar el DX11, la mas rapida es D3D_DRIVER_TYPE_HARDWARE pero solo se puede usar cuando lo soporte el hardware
		//otra opcion es D3D_DRIVER_TYPE_WARP que emula el DX11 en los equipos que no lo soportan
		//la opcion menos recomendada es D3D_DRIVER_TYPE_SOFTWARE, es la mas lenta y solo es util cuando se libera una version de DX que no sea soportada por hardware
		D3D_DRIVER_TYPE driverTypes[]=
		{
			D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_SOFTWARE
		};
		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

		//La version de DX que utilizara, en este caso el DX11
		D3D_FEATURE_LEVEL featureLevels[]=
		{
			D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0
		};
		unsigned int totalFeaturesLevels = ARRAYSIZE(featureLevels);

		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = heigth;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.Windowed = true;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		HRESULT result;
		unsigned int driver = 0, creationFlags = 0;
		for(driver = 0; driver<totalDriverTypes; driver++)
		{
			result = D3D11CreateDeviceAndSwapChain(0, driverTypes[driver], 0,
				creationFlags, featureLevels, totalFeaturesLevels, 
				D3D11_SDK_VERSION, &swapChainDesc, &swapChain,
				&d3dDevice, &featureLevel, &d3dContext);

			if(SUCCEEDED(result))
			{
				driverType = driverTypes[driver];
				break;
			}
		}

		if(FAILED(result))
		{

			//Error al crear el Direct3D device
			return false;
		}
		
		ID3D11Texture2D* backBufferTexture;
		result = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);
		if(FAILED(result))
		{
			//"Error al crear el swapChainBuffer
			return false;
		}

		result = d3dDevice->CreateRenderTargetView(backBufferTexture, 0, &backBufferTarget);
		if(backBufferTexture)
			backBufferTexture->Release();

		if(FAILED(result))
		{
			//Error al crear el renderTargetView
			return false;
		}


		D3D11_VIEWPORT viewport;
		viewport.Width = (FLOAT)width;
		viewport.Height = (FLOAT)heigth;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		d3dContext->RSSetViewports(1, &viewport);

		D3D11_TEXTURE2D_DESC depthTexDesc;
		ZeroMemory(&depthTexDesc, sizeof(depthTexDesc));
		depthTexDesc.Width = width;
		depthTexDesc.Height = heigth;
		depthTexDesc.MipLevels = 1;
		depthTexDesc.ArraySize = 1;
		depthTexDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthTexDesc.SampleDesc.Count = 1;
		depthTexDesc.SampleDesc.Quality = 0;
		depthTexDesc.Usage = D3D11_USAGE_DEFAULT;
		depthTexDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthTexDesc.CPUAccessFlags = 0;
		depthTexDesc.MiscFlags = 0;
		
		result = d3dDevice->CreateTexture2D(&depthTexDesc, NULL, &depthTexture);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear la DepthTexture", MB_OK);
			return false;
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		ZeroMemory(&descDSV, sizeof(descDSV));
		descDSV.Format = depthTexDesc.Format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		result = d3dDevice->CreateDepthStencilView(depthTexture, &descDSV, &depthStencilView);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el depth stencil target view", MB_OK);
			return false;
		}

		d3dContext->OMSetRenderTargets(1, &backBufferTarget, depthStencilView);

		return true;			
		
	}

	void LiberaD3D(void)
	{
		if(depthTexture)
			depthTexture->Release();
		if(depthStencilView)
			depthStencilView->Release();
		if(backBufferTarget)
			backBufferTarget->Release();
		if(swapChain)
			swapChain->Release();
		if(d3dContext)
			d3dContext->Release();
		if(d3dDevice)
			d3dDevice->Release();

		depthTexture = 0;
		depthStencilView = 0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
	}
	
	void Render(void)
	{	
		time++;

		float sphere[3] = { 0,0,0 };
		float prevPos[3] = { camara->posCam.x, camara->posCam.z, camara->posCam.z };
		static float angle = 0.0f;
		angle += izqder;
		if (angle >= 360) angle = 0.0f;

		static float angleA = 0.0f;
		angleA += arriaba;
		if (angleA >= 360) angleA = 0.0f;
		bool collide = false;
		if (d3dContext == 0)
			return;

		posCam = camara->posCam;

		float clearColor[4] = { 0, 0, 0, 1.0f };
		d3dContext->ClearRenderTargetView(backBufferTarget, clearColor);
		d3dContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);

		//camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 12; // Posición en Y de la cámara
		//camara->UpdateCam(vel, velSides, arriaba, izqder); // Hay que agregar el velSides acá también para moverse de izq a der



		if (!Vehiculo) { // FIRST PERSON

			if (firstPerson) {
				camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 4;
				camara->UpdateCam(vel, velSides, arriaba, izqder);
			}
			else {
				camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 10;
				camara->UpdateCam(vel, velSides, arriaba, izqder);
			}


			if (once)
			{
				camara->UpdateCam(vel, velSides, arriaba, izqder);
				once = false;
			}
		}
		else {
			if(firstPerson)
			camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 15;
			else {
				camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 17;

			}

			if (once)
			{
				camara->UpdateCam(vel, velSides, arriaba, izqder);
				once = false;
			}

			else
			{
				camara->UpdateCam(vel, velSides, arriaba, izqder);
			}
		}


		
		///------------------------COLISIONES


		
			if (CollisionONE(camara->posCam.x, camara->posCam.z) == true)
			{

				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];

			}

			if (CollisionTWO(camara->posCam.x, camara->posCam.z) == true)
			{

				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];

			}
			if (CollisionTHREE(camara->posCam.x, camara->posCam.z) == true)
			{

				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];

			}
			if (CollisionFOUR(camara->posCam.x, camara->posCam.z) == true)
			{

				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];

			}

			


			if (PayasoModel->Collision(camara->posCam.x, camara->posCam.z) == true)
			{
				if (PayasoModel->GetdoOnce() == true)
				{

					payasos = payasos + 1;
					camara->posCam.x = prevPos[0];
					camara->posCam.z = prevPos[2];
					PayasoModel->invalidateDoOnce();

				}
				PayasoModel->Invisible();

			}



			if (PayasoModel2->Collision(camara->posCam.x, camara->posCam.z) == true)
			{
				if (PayasoModel2->GetdoOnce() == true)
				{

					payasos = payasos + 1;
					camara->posCam.x = prevPos[0];
					camara->posCam.z = prevPos[2];
					PayasoModel2->invalidateDoOnce();

				}
				PayasoModel2->Invisible();

			}
			if (PayasoModel3->Collision(camara->posCam.x, camara->posCam.z) == true)
			{
				if (PayasoModel3->GetdoOnce() == true)
				{

					payasos = payasos + 1;
					camara->posCam.x = prevPos[0];
					camara->posCam.z = prevPos[2];
					PayasoModel3->invalidateDoOnce();

				}
				PayasoModel3->Invisible();

			}
			if (PayasoModel4->Collision(camara->posCam.x, camara->posCam.z) == true)
			{
				if (PayasoModel4->GetdoOnce() == true)
				{

					payasos = payasos + 1;
					camara->posCam.x = prevPos[0];
					camara->posCam.z = prevPos[2];
					PayasoModel4->invalidateDoOnce();

				}
				PayasoModel4->Invisible();

			}
			


		if (Cofre->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			if (Cofre->GetdoOnce() == true)
			{

				payasos=payasos+1;
				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];
				Cofre->invalidateDoOnce();
				
			}
			Cofre->Invisible();

		}

		

		if (Circo->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
		
				camara->posCam.x = prevPos[0];
				camara->posCam.z = prevPos[2];

		}


		if (Cabaña->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}


		if (Cabaña2->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}


		if (quack->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}
		if (torre->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}
		if (bote->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}
		if (fuente->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}
		if (lampara->Collision(camara->posCam.x, camara->posCam.z) == true)
		{
			camara->posCam.x = prevPos[0];
			camara->posCam.z = prevPos[2];
		}





		skydome->Update(camara->vista, camara->proyeccion);

		float camPosXZ[2] = { camara->posCam.x, camara->posCam.z };

		TurnOffDepth();

		skydome->Render(camara->posCam, 0);

		TurnOnDepth();

		terreno->Draw(camara->vista, camara->proyeccion);
		TurnOnAlphaBlending();

		billboard->Draw(camara->vista, camara->proyeccion, camara->posCam,0, 0, terreno->Superficie(100, 20), 40, uv1, uv2, uv3, uv4, frameBillboard, false, false);

		billboard2->Draw(camara->vista, camara->proyeccion, camara->posCam,110, 23, terreno->Superficie(100, 20), 40, uv1, uv2, uv3, uv4, frameBillboard, false, false);


		billboard3->Draw(camara->vista, camara->proyeccion, camara->posCam,0, -45, terreno->Superficie(100, 20), 40, uv1, uv2, uv3, uv4, frameBillboard, false, false);

	
		billboard4->Draw(camara->vista, camara->proyeccion, camara->posCam,-210, -178, terreno->Superficie(100, 20), 40, uv1, uv2, uv3, uv4, frameBillboard, false, false);


		TurnOnAlphaBlending();


		Olas = cos(time/190)*.2;
		Water->Draw(camara->vista, camara->proyeccion, camara->posCam, 347, 185, (terreno->Superficie(100, 20)* Olas+10), 500, uv1, uv2, uv3, uv4, animacionagua, false, true);
		TurnOffAlphaBlending();
			
	

		tren->rotation = (D3DXToRadian(-50.0f) + angle);
		tren->Update(camara->posCam.x, camara->posCam.z);


		trenpivot->rotation = (D3DXToRadian(-50.0f) + angle);
		trenpivot->Update(camara->posCam.x, camara->posCam.z);


		Vaca->rotation = (D3DXToRadian(-50.0f) + angle);
		Vaca->Update(camara->posCam.x, camara->posCam.z);


		Vacapivot->rotation = (D3DXToRadian(-50.0f) + angle);
		Vacapivot->Update(camara->posCam.x, camara->posCam.z);


		//TurnOffAlphaBlending();
		if (Vehiculo) {

			if (firstPerson)
				Vaca->Draw(camara->vista, camara->proyeccion, camara->posCam.y - 14, camara->posCam, 10.0f, tren->rotation + 4, 'Y', 1);

			else
				Vacapivot->Draw(camara->vista, camara->proyeccion, camara->posCam.y - 14, camara->posCam, 10.0f, tren->rotation + 4, 'Y', 1);

		}
		else {

			if (firstPerson)
				tren->Draw(camara->vista, camara->proyeccion, camara->posCam.y - 14, camara->posCam, 10.0f, tren->rotation + 4, 'Y', 1);
			else
				trenpivot->Draw(camara->vista, camara->proyeccion, camara->posCam.y - 14, camara->posCam, 10.0f, tren->rotation + 4, 'Y', 1);
		}


		Colision->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', .1);
		


		Cofre->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 14.1);

		PayasoModel->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 14.1);
		PayasoModel2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 14.1);
		PayasoModel3->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 14.1);
		PayasoModel4->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100)-20, camara->posCam, 10.0f, 0, 'A', 14.1);

		Circo->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 3.5);

		Cabaña->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 3.5);

		Cabaña2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100)-15, camara->posCam, 10.0f, 0, 'A', 30);

		bote->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 10);

		torre->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100)-3, camara->posCam, 10.0f, 0, 'A', 5);

		quack->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 0.1);

		fuente->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100)-1, camara->posCam, 10.0f, 0, 'A', 0.09);

		lampara->Draw(camara->vista, camara->proyeccion, terreno->Superficie(200, 100), camara->posCam, 10.0f, 0, 'A', 0.1);


		float reducido=time/3000;


		if (payasos == 5) {
			Win->Draw(0, 0);
			
				MessageBox(hWnd, L"HAZ GANADO!! Gracias Por jugar", L"INFO", MB_OK);

				DestroyWindow(hWnd);
			
		}

		if (reducido > 1.2) {
			GameOver->Draw(0, 0);
			if (reducido>1.21) {
				MessageBox(hWnd, L"Gracias Por jugar", L"INFO", MB_OK);

				DestroyWindow(hWnd);
			}

		}

		timegui->Draw(-.7+ reducido, -.6);

		Linea->Draw(.1, -.6);

		if (Esta==true) {

			Explosion->Draw(.1, .3);
			Esta = false;
		}


		if (payasos >= 1) {
			payakillD->Draw(-0.85, 0.85);
			if(Flag==false){
			Esta = true;
			Flag = true;

			}
		}
		else
			payakill->Draw(-0.85, 0.85);

	
		if (payasos >= 2) {
			payakillD2->Draw(-0.75, 0.85);
			if (Flag2 == false) {
				Esta = true;
				Flag2 = true;
			}
		}
		else
			payakill2->Draw(-0.75, 0.85);



			if (payasos >= 3) {
				payakillD3->Draw(-0.65, 0.85);
				if (Flag3 == false) {
					Esta = true;
					Flag3 = true;
				}
			}
		else
			payakill3->Draw(-0.65, 0.85);

			if (payasos >= 4) {
				payakillD4->Draw(-0.55, 0.85);
				if (Flag4 == false) {
					Esta = true;
					Flag4 = true;
				}
			}
		else
			payakill4->Draw(-0.55, 0.85);


			if (payasos >= 5) {
				payakillD5->Draw(-0.45, 0.85);
				if (Flag5 == false) {
					Esta = true;
					Flag5 = true;
				}
			}
		else
			payakill5->Draw(-0.45, 0.85);






		//lake->Draw(camara->vista, camara->proyeccion, camara->posCam, 0, .5, 1);

		swapChain->Present( 1, 0 );
	}

	bool isPointInsideSphere(float* point, float* sphere) {
		bool collition = false;

		float distance = sqrt((point[0] - sphere[0]) * (point[0] - sphere[0]) +
			(point[1] - sphere[1]) * (point[1] - sphere[1]));

		if (distance < sphere[2])
			collition = true;
		return collition;
	}

	//Activa el alpha blend para dibujar con transparencias
	void TurnOnAlphaBlending()
	{
		float blendFactor[4];
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;
		HRESULT result;

		D3D11_BLEND_DESC descABSD;
		ZeroMemory(&descABSD, sizeof(D3D11_BLEND_DESC));
		descABSD.RenderTarget[0].BlendEnable = TRUE;
		descABSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descABSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descABSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;

		result = d3dDevice->CreateBlendState(&descABSD, &alphaBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(alphaBlendState, blendFactor, 0xffffffff);
	}

	//Regresa al blend normal(solido)
	void TurnOffAlphaBlending()
	{
		D3D11_BLEND_DESC descCBSD;
		ZeroMemory(&descCBSD, sizeof(D3D11_BLEND_DESC));
		descCBSD.RenderTarget[0].BlendEnable = FALSE;
		descCBSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descCBSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descCBSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;
		HRESULT result;

		result = d3dDevice->CreateBlendState(&descCBSD, &commonBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(commonBlendState, NULL, 0xffffffff);
	}

	void TurnOnDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDSD;
		ZeroMemory(&descDSD, sizeof(descDSD));
		descDSD.DepthEnable = true;
		descDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDSD.StencilEnable=true;
		descDSD.StencilReadMask = 0xFF;
		descDSD.StencilWriteMask = 0xFF;
		descDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDSD, &depthStencilState);
		
		d3dContext->OMSetDepthStencilState(depthStencilState, 1);
	}

	void TurnOffDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDDSD;
		ZeroMemory(&descDDSD, sizeof(descDDSD));
		descDDSD.DepthEnable = false;
		descDDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDDSD.StencilEnable=true;
		descDDSD.StencilReadMask = 0xFF;
		descDDSD.StencilWriteMask = 0xFF;
		descDDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDDSD, &depthStencilDisabledState);
		d3dContext->OMSetDepthStencilState(depthStencilDisabledState, 1);
	}

	void billCargaFuego()
	{
		uv1[0].u = .125;
		uv2[0].u = .125;
		uv3[0].u = 0;
		uv4[0].u = 0;

		uv1[0].v = .25;
		uv2[0].v = 0;
		uv3[0].v = 0;
		uv4[0].v = .25;


		for (int j = 0; j < 8; j++) {
			uv1[j].u = uv1[0].u + (j * .125);
			uv2[j].u = uv2[0].u + (j * .125);
			uv3[j].u = uv3[0].u + (j * .125);
			uv4[j].u = uv4[0].u + (j * .125);

			uv1[j].v = .25;
			uv2[j].v = 0;
			uv3[j].v = 0;
			uv4[j].v = .25;
		}
		for (int j = 0; j < 8; j++) {
			uv1[j + 8].u = uv1[0].u + (j * .125);
			uv2[j + 8].u = uv2[0].u + (j * .125);
			uv3[j + 8].u = uv3[0].u + (j * .125);
			uv4[j + 8].u = uv4[0].u + (j * .125);

			uv1[j + 8].v = .5;
			uv2[j + 8].v = .25;
			uv3[j + 8].v = .25;
			uv4[j + 8].v = .5;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 16].u = uv1[0].u + (j * .125);
			uv2[j + 16].u = uv2[0].u + (j * .125);
			uv3[j + 16].u = uv3[0].u + (j * .125);
			uv4[j + 16].u = uv4[0].u + (j * .125);

			uv1[j + 16].v = .75;
			uv2[j + 16].v = .5;
			uv3[j + 16].v = .5;
			uv4[j + 16].v = .75;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 24].u = uv1[0].u + (j * .125);
			uv2[j + 24].u = uv2[0].u + (j * .125);
			uv3[j + 24].u = uv3[0].u + (j * .125);
			uv4[j + 24].u = uv4[0].u + (j * .125);

			uv1[j + 24].v = 1;
			uv2[j + 24].v = .75;
			uv3[j + 24].v = .75;
			uv4[j + 24].v = 1;
		}
	}

};
#endif