Texture2D colorMap : register(t0);
Texture2D specMap : register(t1);

SamplerState colorSampler : register(s0);

cbuffer cbChangerEveryFrame : register(b0)
{
	matrix worldMatrix;
};

cbuffer cbNeverChanges : register(b1)
{
	matrix viewMatrix;
};

cbuffer cbChangeOnResize : register(b2)
{
	matrix projMatrix;
};

cbuffer cbChangesOccasionally : register(b3)
{
	float3 cameraPos;
};

cbuffer cbChangesOccasionally : register(b4)
{
	float specForce;
};

cbuffer cbChangesOccasionally : register(b5)
{
	float luzx;
};

cbuffer cbChangesOccasionally : register(b6)
{
	float valB;
};

struct VS_Input
{
	float4 pos : POSITION;
	float2 tex0 : TEXCOORD0;	
	float3 normal : NORMAL0;
};

struct PS_Input
{
	float4 pos : SV_POSITION;
	float2 tex0 : TEXCOORD0;	
	float3 normal : TEXCOORD1;
	float3 campos : TEXCOORD2;
	float3 lightVec : TEXCOORD4;
	float specForce : TEXCOORD3;
	float luzx : TEXCOORD5;
	float valB : TEXCOORD6;
};

PS_Input VS_Main(VS_Input vertex)
{
	float4 worldPosition;

	PS_Input vsOut = (PS_Input)0;

	//Initial transformations
	worldPosition = mul(vertex.pos, worldMatrix);
	vsOut.pos = mul(vertex.pos, worldMatrix);//practicamente dibuja los modelos
	vsOut.pos = mul(vsOut.pos, viewMatrix); //si lo quito mantiene los objetos en la camara, osea no importa hacia donde mire los veo
	vsOut.pos = mul(vsOut.pos, projMatrix); //tambien dibuja los modelos

	vsOut.tex0 = vertex.tex0;//pinta las texturas

	vsOut.normal = mul(vertex.normal, (float3x3)worldMatrix);
	vsOut.normal = normalize(vsOut.normal);

	vsOut.luzx = luzx;
	//set light position
	float3 lightDir = float3(luzx, 200.0f, 0.0f); // lightDirection
	//Calculate light vector
	vsOut.lightVec = normalize(lightDir - worldPosition); //para saber si le esta dando la luz, que tan lejos y si le va a estar afectando

	//Calculate camara vector
	vsOut.campos = normalize(cameraPos.xyz - worldPosition.xyz); //como se va a afectar la luz por vertice de acuerdo a la camara
	/*vsOut.campos = cameraPos.xyz - worldPosition.xyz;

	vsOut.campos = normalize(vsOut.campos);*/

	vsOut.specForce = specForce;
	vsOut.valB = valB;

	return vsOut;
}

float4 PS_Main(PS_Input pix) : SV_TARGET
{
	float4 textureColor;
	float3 lightDir;
	float lightIntensity;
	float4 color;
	float3 reflection;
	float4 specular;
	float4 specularMap;
	float4 finalSpec;

	lightDir = float3(pix.luzx, 200.0f, 0.0f); // lightDirection

	textureColor = colorMap.Sample(colorSampler, pix.tex0);
	float4 ambientColor = float4(0.2f, 0.2f, pix.valB, 1);
	float4 diffuseColor = float4(1.0f, 1.0f, 1.0f, 1);
	float4 specularColor = float4(0.9f, 0.8f, 0.0f, 1);

	//specular = float4(0.0, 0.0, 0.0, 1.0); //specular color
	specularMap = specMap.Sample(colorSampler, pix.tex0);

	//Get parameters//los obtenemos del vertex
	float3 normal = normalize(pix.normal);
	float3 lightVec = normalize(pix.lightVec);
	float3 cameraVec = normalize(pix.campos);
	//lightIntensity = saturate(dot(pix.normal, lightDir));
	//Calculate diffuse lighting
	float diffuseTerm = saturate(dot(normal, lightVec));

	//Calculate specular lighting
	float3 halfVec = normalize(lightVec + cameraVec);
	float specularTerm = pow(saturate(dot(normal, halfVec)), 32);

	//Calculate final Color
	float4 sumColor = textureColor * (ambientColor + diffuseColor * diffuseTerm + specularColor * specularTerm);
	//float4 finalColor = textureColor * (finalColor, 1.0f);
	return sumColor;
	//return finalColor;
}