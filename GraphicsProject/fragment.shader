#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 iDirection;
uniform vec3 iAmbient;
uniform vec3 iDiffuse;
uniform vec3 iSpecular;

uniform vec3 iDirection1;
uniform vec3 iAmbient1;
uniform vec3 iDiffuse1;
uniform vec3 iSpecular1;

uniform vec3 cameraPosition;

out vec4 pColor;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection);
	vec3 iNormal1 = normalize(iDirection1);

	//Snow
	if (kNormal.y > 0.5f) {
		vec4 red = vec4( 1.0f, 0.0f, 0.0f, 1.0f );
		pColor = red;
	}

	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular * specularTerm;

	vec4 color = vec4(ambientColor + diffuseColor + specularColor, 1.0f);



	//Calculate ambient color again
	vec3 ambientColor1 = (fColor.xyz + kAmbient) * iAmbient1;

	//Calculate diffuse color
	float lambertTerm1 = dot(kNormal, -iNormal1);
	lambertTerm1 = max(0.0f, min(1.0f, lambertTerm1));
	vec3 diffuseColor1 = (fColor.xyz + kDiffuse) * iDiffuse1 * lambertTerm1;

	//Calculate specular color
	vec3 surfaceToView1 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal1 = reflect(iNormal1, kNormal);
	float specularTerm1 = dot(surfaceToView1, reflectionNormal1);
	specularTerm1 = max(0.0f, specularTerm1);
	specularTerm1 = pow(specularTerm1, kSpecularPower);
	vec3 specularColor1 = (fColor.xyz + kSpecular) * iSpecular1 * specularTerm1;

	vec4 color1 = vec4(ambientColor1 + diffuseColor1 + specularColor1, 1.0f);
	pColor = color + color1;
}
