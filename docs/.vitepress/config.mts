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
            {
                text: "DSA",
                link: "/dsa/datastructure.md",
            },
        ],

        sidebar: {
            "/dsa": [
                {
                    text: "Data Structure & Algorithm",
                    items: [
                        {
                            text: "Data Structure",
                            items: [
                                {
                                    text: "Data Structure: Intro",
                                    link: "/dsa/datastructure.md",
                                },
                                {
                                    text: "Tree",
                                    link: "/dsa/tree/tree.md",
                                    items: [
                                        {
                                            text: "Binary Tree",
                                            link: "/dsa/tree/binary_tree/binary_tree.md",
                                        },
                                    ],
                                },
                            ],
                        },

                        {
                            text: "Algorithm",
                            items: [
                                {
                                    text: "Algorithm: Intro",
                                    link: "/dsa/algorithm.md",
                                },
                            ],
                        },
                    ],
                },
                {
                    text: "Algorithm",
                    items: [
                        {
                            text: "Introduction",
                            link: "/dsa/algorithm.md",
                        },
                    ],
                },
            ],
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
