import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
    title: "Job Prep Doc",
    description: "Preparation Materials",
    themeConfig: {
        // https://vitepress.dev/reference/default-theme-config
        nav: [
            { text: "Home", link: "/" },
            { text: "Examples", link: "/markdown-examples" },
            {
                text: "Javascript",
                link: "/javascript",
            },
        ],

        sidebar: {
            "/javascript": [
                {
                    text: "Javascript",
                    link: "/javascript",
                },
                {
                    text: "Data Type",
                    items: [
                        { text: "NaN", link: "/javascript/datatype/NaN.md" },
                    ],
                },
            ],
            "/": [
                {
                    text: "Examples",
                    items: [
                        {
                            text: "Markdown Examples",
                            link: "/markdown-examples",
                        },
                        { text: "Runtime API Examples", link: "/api-examples" },
                    ],
                },
            ],
        },

        socialLinks: [
            { icon: "github", link: "https://github.com/vuejs/vitepress" },
        ],
    },
});
