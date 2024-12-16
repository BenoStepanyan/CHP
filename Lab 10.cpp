// SHA256 հեշի հաշվարկ
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(ctx, result, &resultLen);

    EVP_MD_CTX_free(ctx); 

    // Հեշի արդյունքը վերածում ենք հեքսադեցիմալ տողին։
    std::ostringstream hashStream;
    for (unsigned int i = 0; i < resultLen; ++i) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)result[i];
    }
    return hashStream.str();
}

// Օժանդակ ֆունկցիա՝ ֆայլի առկայությունը ստուգելու համար
bool fileExists(const std::string& filePath) {
    return fs::exists(filePath); 
}
